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
            pf::meta::template_fPor_r<pf::meta::members_of<enumInfo>()>([&]<pf::meta::Info valueInfo>() -> std::optional<std::string_view> {
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
