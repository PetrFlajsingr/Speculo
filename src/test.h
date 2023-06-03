

#include "tmp.hpp"

#include "generated/test.hpp"


namespace pf {
    class Hoho : Haha {
        PF_META_GENERATED();

    private:
        int stan;
    };

    enum class [[pf::no_sti]] Hihi {};
    enum class [[using pf: operators(()()()((())), [[nodiscard]], 1ll, 1.011, [] {}(), "yeet", 'a', [][][] :: : 3214234... [][][][]),
                 hihi()]] [[pf::operators2(1ll, 1.011, "yeet"), pf::hihi2]] [[nodiscard]] SomeEnum : int{
            Value1 [[pf::test, pf::test2]] [[pf::test3]], Value2};

    struct [[pf::no_sti]] B1 {};
    struct B2 {
        [[test1]] int [[test2]] value [[test3]]{};
        [[test1]] int [[test2]] value2 [[test3]] = 10;
        [[test1]] inline static int [[test2]] value3 [[test3]] = 10;
    };
    struct [[lala(111), lala(222)]] [[lala(333, 444)]] B3 {};

    struct [[nodiscard]] [[first]] [[second, third]] A : B1, B2, private B3 {
        PF_META_GENERATED();

        constexpr A() : test{0} {}

        A(int a) : test{a} {}

        A(int sadfsdf, float asdsa) {}

        constexpr ~A() {}

        A &operator=(const A &) { return *this; }

        A &operator=(A &&) = delete;


        [[maybe_unused, nodiscard]] consteval int foo([[letadlo(dzea, dzea2)]] int dzea, [[yuh]] [[yuh2]] float A) const [[kjhnn]] {
            return test + dzea + A;
        }

        [[maybe_unused]] virtual int foo2([[letadlo()]] int dzea2) [[kjhnn]] final {
            [[yeetus]];
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
        virtual ~B() = default;

        virtual void pure_foo(int a) = 0;

        virtual void virt_foo(int a) {}
    };

    struct Test : public A, protected B {
        PF_META_GENERATED();
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
    enum class E9 { A, B, C, D, E };

}// namespace pf

PF_META_GENERATED_HEADER();