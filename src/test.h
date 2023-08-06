

#include <speculo/macros.hpp>
#include <functional>
#include "generated/test.hpp"

namespace S{
    constexpr auto Value = 10 * 15;
}

namespace A {
    constexpr auto Value = 1;
}
namespace S {
    enum class [[speculo::no_sti]]  E{
        A = 100, B = 50, C, D
    };
    struct [[speculo::no_sti]]  T {
        const std::array<int, Value * A::Value + 10> yeet;
    };
    using namespace std;
    struct F {
        function<void(const T&, E&&)> testFnc;
    };
  /*  class Hoho {
        //SPECULO_GENERATED()
        static inline auto hue = "SPECULO_GENERATED()";
        SPECULO_GENERATED()

        Hoho() {}

    private:
        int stan;
    };

    enum class [[speculo::no_sti]] Hihi {};
    enum class [[using pf: operators(()()()((())), [[nodiscard]], 1ll, 1.011, [] {}(), "yeet", 'a'),
                 hihi()]] [[pf::operators2(1ll, 1.011, "yeet"), pf::hihi2]] [[nodiscard]] SomeEnum : int{
            Value1 [[pf::test, pf::test2]] [[pf::test3]], Value2};

    struct [[speculo::no_sti]] B1 {
        SPECULO_GENERATED()
    };
    struct B2 {
        SPECULO_GENERATED()
        int value{};
        int value2 = 10;
        inline static int value3 = 10;
    };
    struct [[t::lala(111), t::lala(222)]] [[t::lala(333, 444)]] B3 {
        SPECULO_GENERATED()
    };

    struct [[nodiscard]] [[t::first]] [[t::second, t::third]] A : B1, B2, private B3 {
        SPECULO_GENERATED()

        constexpr A() : test{0} {}

        A(int a) : test{a} {}

        A(int sadfsdf, float asdsa) {}

        constexpr ~A() {}

        A &operator=(const A &) { return *this; }

        A &operator=(A &&) = delete;


        [[maybe_unused, nodiscard]] consteval int foo([[t::letadlo(dzea, dzea2)]] int dzea, [[t::yuh]] [[t::yuh2]] float A) const
                [[t::kjhnn]] {
            return test + dzea + A;
        }

        [[maybe_unused]] virtual int foo2([[t::letadlo()]] int dzea2) [[t::kjhnn]] final {
            [[t::yeetus]];
            return 0;
        }

        int test{10};
        constexpr static auto constexpr_test = 123;

    private:
        int letadlo() { return test; }

        constexpr void letadlo2() {}

        void letadlo3(int asdasdas) {}

        int privateVar{};
        int privateVar2{};
        int privateVar3{};
        int privateVar4{};

        static int statFoo() { return 4324; }

        inline static int statValue = 19;
    };

    struct B {
        SPECULO_GENERATED()
        virtual ~B() = default;

        virtual void pure_foo(int a) = 0;

        virtual void virt_foo(int a) {}
    };

    struct Test : public A, protected B {
        SPECULO_GENERATED()

    public:
        Test() = default;

        consteval explicit Test(A v) {}

        consteval Test(const int &v1, int v2) {}

        Test(const Test &) = delete;

        Test &operator=(const Test &) noexcept = default;

        template<typename T>
        Test(T) {}

    protected:
        void pure_foo(int a) override {}

        void virt_foo(int a) override { B::virt_foo(a); }

    public:
        int a{};
        int b{};
        float c{}, d{};

        inline static int inline_static_int = 10;
        static int static_int;

        void foo(int a, int b){};

    protected:
        void foo(int a, int b) const {};

        static void bar(float a) {}

    private:
        static void bar(float a, int c) {}
    };


    enum class EmptyEnum {};

    enum class E1 { A, B, C, D, E };
    enum class E2 { A, B, C, D, E };
    enum class E3 { A, B, C, D, E };
    enum class E4 { A, B, C, D, E };
    enum class E5 { A, B, C, D, E };
    enum class E6 { A, B, C, D, E };
    enum class E7 { A, B, C, D, E };
    enum class E8 { A, B, C, D, E };
    enum class E9 { A, B, C, D, E };*/

}// namespace test

SPECULO_GENERATED_HEADER()