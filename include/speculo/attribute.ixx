module;

#include <string_view>
#include <span>

export module speculo:attribute;

export namespace speculo {
    struct Attribute {
        constexpr Attribute(std::string_view ns, std::string_view n, std::span<const std::string_view> args)
            : nnamespace{ns}, name{n}, arguments{args} {}

        std::string_view nnamespace;
        std::string_view name;
        std::span<const std::string_view> arguments;
    };
}
