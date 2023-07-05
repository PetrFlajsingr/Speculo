# speculo_gen

Static type info generation system.

* Only supports record types (classes, structs and unions) and enums.
  * That includes their member functions, static var etc. but not nested types.
  * For classes using the macro `SPECULO_GENERATED()` is required in order to allow static structure's access to internals.
* Usage example of string<->enum conversion:
```cpp
/**
 * Convert enum value to a string.
 */
 template<typename E>
[[nodiscard]] constexpr std::string_view to_string(E value) {
    constexpr auto enumInfo = SPECULO_REFLECT(E); // create an object for accessing static type info
    // wanna-be 'template for' for statically iterating over constexpr containers - this version has an early exit
    const auto result =
            speculo::template_for_r<speculo::members_of<enumInfo>()>([&]<speculo::Info valueInfo>() -> std::optional<std::string_view> {
                if (SPECULO_SPLICE(valueInfo) == value) { return std::optional{speculo::name_of<valueInfo>()}; }
                return std::nullopt;
            });
    return result.value_or("<INVALID_ENUM_VALUE>");
}
/**
 * Find enum value for a string.
 */
template<typename E>
[[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
    constexpr auto enumInfo = SPECULO_REFLECT(E);
    return speculo::template_for_r<speculo::members_of<enumInfo>()>([&]<speculo::Info valueInfo>() -> std::optional<E> {
        if (speculo::name_of<valueInfo>() == name) { return SPECULO_SPLICE(valueInfo); }
        return std::nullopt;
    });
}
```

* `SPECULO_REFLECT(X)` macro creates an instance of `speculo::Info`, which serves as an accessor to static type info data. It currently supports types and enum values.
* `SPECULO_SPLICE(X)` macro tries to bring the meta structure as close as possible to the construct it represents. `SPECULO_SPLICE(MyClassInfo)` is then equal to `MyClass`.
  * Since constructors can't be stored as pointers they are currently wrapped in a lambda.
  * Destructors behave the same way.

Built-in attributes:
* `speculo::no_sti` - disables STI generation for type

## Usage
1. Copy `script` folder to the root of your project.
2. Copy `speculo.cmake` to your project.
3. Build `speculo_gen` target and put the resulting exe wherever you want.
4. Register your project in CMake:
  ```cmake
  include(cmake/speculo.cmake)
  # ... 
  list(APPEND CXXFLAGS "-std=c++20") # gotta use clang flags
  
  speculo_register(
          TARGET meta_test
          FLAGS ${CXXFLAGS}
          HEADERS src/test.h
          FORMAT
  )
  ```
5. Provide cmake with the path to `speculo_gen` executable `-SPECULO_GEN_EXE_PATH=<path_to_exe>`

## Extensions
#### Attributes
The tool collects attributes wherever they are allowed by the standard. They are accessed as follows:
```cpp
constexpr auto Trefl = SPECULO_REFLECT(T);
constexpr auto attributes = speculo::attributes_of<Trefl>();
std::ranges::for_each(attributes, [](const Attribute &attribute) {
   std::cout << attribute.name << ": \n";
   std::ranges::for_each(attribute.arguments, [](std::string_view argument) {
      std::cout << "\t" << argument << "\n"; 
   });
});
```

#### Template for
To allow constexpr iteration over ranges of reflection data `speculo::template_for` is provided:
```cpp
speculo::template_for<speculo::members_of<enumInfo>()>([]<speculo::Info VI>() { 
    std::cout << speculo::name_of<VI>() << "=" << static_cast<int>(SPECULO_SPLICE(VI)) << std::endl; 
});
```
And an early exit variant returning `std::optional`:
```cpp
const auto result = speculo::template_for_r<speculo::members_of<enumInfo>()>(
        [&]<speculo::Info valueInfo>() -> std::optional<std::string_view> {
            if (SPECULO_SPLICE(valueInfo) == value) { return std::optional{speculo::name_of<valueInfo>()}; }
            return std::nullopt;
        });
```

## Weirdness
#### Bit fields
Since an address to a bit field can not be taken it has to be wrapped. Current way to access bit fields:
```cpp
constexpr auto Trefl = SPECULO_REFLECT(T);
constexpr auto members = speculo::members_of<Trefl>();
constexpr auto bitfield1Refl = members[1]; // let's assume 1 is a bitfield
T t{};
// create read write accessor (ptr to t is not const)
auto accessor = speculo::create_bit_field_accessor<bitfield1Refl>(&t);
// assuming bitfield is an uint32_t
accessor = 10u;
std::cout << static_cast<std::uint32_t>(accessor);

const T *constT = &t;
// create a read only accessor
auto constAccessor = speculo::create_bit_field_accessor<bitfield1Refl>(constT);
std::cout << static_cast<std::uint32_t>(constAccessor);
```

#### Constructors
Address of a constructor is impossible to be taken, so constructors are currently wrapped in a lambda.
TODO: demo

#### Destructors
Address of a destructors is impossible to be taken, so constructors are currently wrapped in a lambda.
TODO: demo

## Codegen plugins
Dynamic library plugins can be created and used by placing them in a `plugins` directory next to the created executable. Simple example [https://github.com/PetrFlajsingr/speculo_plugin_template](https://github.com/PetrFlajsingr/speculo_plugin_template).

The plugin library needs to provide a subclass of `speculo::gen::CodeGenerator` and the following interface:
```cpp
extern "C" {
speculo::gen::CodeGenerator *create();

void destroy(speculo::gen::CodeGenerator *ptr);
}
```

The plugin can generate code which will be placed inside `SPECULO_GENERATED()` for given type, `SPECULO_GENERATED_HEADER()` for header sources and in `<filename>.generated.cpp` for implementation.