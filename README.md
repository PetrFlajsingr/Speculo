# pf_meta_gen

Static type info generation system.

* Only supports record types (classes, structs and unions) and enums.
  * That includes their member functions, static var etc. but not nested types.
  * For classes using the macro `PF_META_GENERATED()` is required in order to allow static structure's access to internals.
* Usage example of string<->enum conversion:
```cpp
/**
 * Convert enum value to a string.
 */
 template<typename E>
[[nodiscard]] constexpr std::string_view to_string(E value) {
    constexpr auto enumInfo = PF_REFLECT(E); // create an object for accessing static type info
    // wanna-be template for for statically iterating over constexpr containers - this version has an early exit
    const auto result =
            pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<std::string_view> {
                if (PF_SPLICE(valueInfo) == value) { return std::optional{pf::meta::name_of<valueInfo>()}; }
                return std::nullopt;
            });
    return result.value_or("<INVALID_ENUM_VALUE>");
}
/**
 * Find enum value for a string.
 */
template<typename E>
[[nodiscard]] constexpr std::optional<E> from_string(std::string_view name) {
    constexpr auto enumInfo = PF_REFLECT(E);
    return pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<E> {
        if (pf::meta::name_of<valueInfo>() == name) { return PF_SPLICE(valueInfo); }
        return std::nullopt;
    });
}
```

* `PF_REFLECT(X)` macro creates an instance of `pf::meta::Info`, which serves as an accessor to static type info data. It currently supports types and enum values.
* `PF_SPLICE(X)` macro tries to bring the meta structure as close as possible to the construct it represents. `PF_SPLICE(MyClassInfo)` is then equal to `MyClass`.
  * Since constructors can't be stored as pointers they are currently wrapped in a lambda.
  * Destructors behave the same way.

Built-in attributes:
* `pf::no_sti` - disables STI generation for type

## Usage
1. Copy `script` folder to the root of your project.
2. Copy `pf_meta.cmake` to your project.
3. Build `pf_meta_gen` target and put the resulting exe wherever you want.
4. Register your project in CMake:
  ```cmake
  include(cmake/pf_meta.cmake)
  # ... 
  list(APPEND CXXFLAGS "-std=c++20") # gotta use clang flags
  
  pf_meta_register(
          TARGET meta_test
          FLAGS ${CXXFLAGS}
          HEADERS src/test.h
          FORMAT
  )
  ```
5. Provide cmake with the path to `pf_meta_gen` executable `-PF_META_GEN_EXE_PATH=<path_to_exe>`

## Extensions
#### Attributes
The tool collects attributes wherever they are allowed by the standard. They are accessed as follows:
```cpp
constexpr auto Trefl = PF_REFLECT(T);
constexpr auto attributes = pf::meta::attributes_of<Trefl>();
std::ranges::for_each(attributes, [](const Attribute &attribute) {
   std::cout << attribute.name << ": \n";
   std::ranges::for_each(attribute.arguments, [](std::string_view argument) {
      std::cout << "\t" << argument << "\n"; 
   });
});
```

#### Template for
To allow constexpr iteration over ranges of reflection data `pf::meta::template_for` is provided:
```cpp
pf::meta::template_for<pf::meta::members_of<enumInfo>()>([]<pf::meta::Info VI>() { 
    std::cout << pf::meta::name_of<VI>() << "=" << static_cast<int>(PF_SPLICE(VI)) << std::endl; 
});
```
And an early exit variant returning `std::optional`:
```cpp
const auto result = pf::meta::template_for_r<pf::meta::members_of<enumInfo>()>(
        [&]<pf::meta::Info valueInfo>() -> std::optional<std::string_view> {
            if (PF_SPLICE(valueInfo) == value) { return std::optional{pf::meta::name_of<valueInfo>()}; }
            return std::nullopt;
        });
```

## Weirdness
#### Bit fields
Since an address to a bit field can not be taken it has to be wrapped. Current way to access bit fields:
```cpp
constexpr auto Trefl = PF_REFLECT(T);
constexpr auto members = pf::meta::members_of<Trefl>();
constexpr auto bitfield1Refl = members[1]; // let's assume 1 is a bitfield
T t{};
// create read write accessor (ptr to t is not const)
auto accessor = pf::meta::create_bit_field_accessor<bitfield1Refl>(&t);
// assuming bitfield is an uint32_t
accessor = 10u;
std::cout << static_cast<std::uint32_t>(accessor);

const T *constT = &t;
// create a read only accessor
auto constAccessor = pf::meta::create_bit_field_accessor<bitfield1Refl>(constT);
std::cout << static_cast<std::uint32_t>(constAccessor);
```

#### Constructors
Address of a constructor is impossible to be taken, so constructors are currently wrapped in a lambda.
TODO: demo

#### Destructors
Address of a destructors is impossible to be taken, so constructors are currently wrapped in a lambda.
TODO: demo

## Codegen plugins
Dynamic library plugins can be created and used by placing them in a `plugins` directory next to the created executable. Simple example [https://github.com/PetrFlajsingr/pf_meta_plugin_template](https://github.com/PetrFlajsingr/pf_meta_plugin_template).

The plugin library needs to provide a subclass of `pf::meta_gen::CodeGenerator` and the following interface:
```cpp
extern "C" {
pf::meta_gen::CodeGenerator *create();

void destroy(pf::meta_gen::CodeGenerator *ptr);
}
```