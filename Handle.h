//
// Created by xflajs00 on 17.02.2023.
//

#ifndef PF_CLANG_HANDLES_H
#define PF_CLANG_HANDLES_H

#include <concepts>
#include <pf_common/macros.h>

namespace pf::clang {
    template<typename T, typename Deleter, std::invocable<T&> Proj = std::identity>
        requires std::invocable<Deleter, std::invoke_result_t<Proj, T&>>
    class Handle {
    protected:
        using HandleType = Handle;

    public:
        explicit Handle(T &&h, Deleter del = Deleter{}, Proj proj = Proj{})
            requires(!std::is_pointer_v<Deleter>)
            : handle{std::move(h)}, deleter{std::move(del)}, p{std::move(proj)} {}
        explicit Handle(T &&h, Deleter del, Proj proj = Proj{})
            requires(std::is_pointer_v<Deleter>)
            : handle{std::move(h)}, deleter{std::move(del)}, p{std::move(proj)} {}

        Handle(const Handle &) = delete;
        Handle &operator=(const Handle &) = delete;

        Handle(Handle &&other) noexcept : handle{std::move(other.handle)}, deleter{std::move(other.deleter)} { other.moved = true; }
        Handle &operator=(Handle &&other) noexcept {
            if (this == &other) { return *this; }
            handle = std::move(other.handle);
            deleter = std::move(other.deleter);
            other.moved = true;
            return *this;
        }

        ~Handle() {
            if (!moved) {
                std::invoke(deleter, std::invoke(p, handle));
            }
        }

        [[nodiscard]] T &get() { return handle; }
        [[nodiscard]] const T &get() const { return handle; }
        [[nodiscard]] T &operator*() { return get(); }
        [[nodiscard]] const T &operator*() const { return get(); }

    private:
        T handle;
        bool moved = false;
        PF_NOUNIQUEADDRESS Deleter deleter;
        PF_NOUNIQUEADDRESS Proj p;
    };
    using EmptyDeleter = decltype([](auto) {});
    using AddressProj = decltype([](auto &v) { return &v; });


}// namespace pf::clang


#endif//PF_CLANG_HANDLES_H
