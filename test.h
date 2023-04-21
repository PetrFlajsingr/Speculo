

#include <test.generated.h>

namespace pf {
    enum class [[pf::no_sti]] Hihi {};
    enum class [[using pf: operators(()()()((())), [[nodiscard]], 1ll, 1.011, [] {}(), "yeet", 'a', [][][] :: : 3214234... [][][][]),
                 hihi()]] [[pf::operators2(1ll, 1.011, "yeet"), pf::hihi2]] SomeEnum : int{
            Value1 [[pf::test, pf::test2]] [[pf::test3]], Value2
    };

    struct [[pf::no_sti]] B1{};
    struct B2{};
    struct B3{};

    struct [[first]] [[second, third]] A  /*: B1, B2, private B3*/  {
        A(int a) : test{a} {}
        A(int sadfsdf, float asdsa) {}

        A&operator=(const A&) { return *this; }
        A&operator=(A&&) = delete;


        [[yeet]] [[maybe_unused]] int c [[cxvxc]];
        [[maybe_unused]] int foo([[letadlo(dzea, dzea2)]] int dzea, [[yuh]][[yuh2]] float A) [[kjhnn]];
        [[maybe_unused]] int foo2([[letadlo()]] int dzea2) [[kjhnn]] {
            [[yeetus]];
        }

        int test{10};

    private:
        int letadlo() {
            return test;
        }
        void letadlo2() {}
        void letadlo3(int asdasdas) {}

        int privateVar;
        int privateVar2;
        int privateVar3;
        int privateVar4;

        static int statFoo() { return 4324; }
        inline static int statValue = 19;

        // has to be at the end
        PF_META_GENERATED(A)
    };

    /*struct B {
       virtual ~B() = default;
       virtual void pure_foo(int a) = 0;
       virtual void virt_foo(int a) {}
   };

    struct Test : public A, protected virtual B {
    public:
        Test() = default;
        explicit Test(A v) {}
        constexpr Test(const int& v1, int v2) {}
        Test(const Test&) = delete;
        Test &operator=(const Test&) noexcept = default;

        template<typename T>
        Test(T) {}

    protected:
        void pure_foo(int a) override {

        }

        void virt_foo(int a) override {
            B::virt_foo(a);
        }

    public:

        int a;
        int b;
        float c, d;

        inline static int inline_static_int = 10;
        static int static_int;

        void foo(int a, int b){};
    protected:
        void foo(int a, int b) const {};
        static void bar(float a) {}
    private:
        static void bar(float a, int c) {}
    };*/


    /*enum class EmptyEnum {};

    enum class E1 { A, B, C, D, E };
    enum class E2 { A, B, C, D, E };
    enum class E3 { A, B, C, D, E };
    enum class E4 { A, B, C, D, E };
    enum class E5 { A, B, C, D, E };
    enum class E6 { A, B, C, D, E };
    enum class E7 { A, B, C, D, E };
    enum class E8 { A, B, C, D, E };
    enum class E9 { A, B, C, D, E };*/
}// namespace pf