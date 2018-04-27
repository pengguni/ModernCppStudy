#include <iostream>

template<class T, int I> // primary template
struct A {
    void f();
};

template<class T, int I>
void A<T, I>::f() {
    std::cout << "A<T, I>::f()" << std::endl;
}

// partial specialization
template<class T>
struct A<T, 2> {
    void f();
    void g();
    void h();
};

template<class T>
void A<T, 2>::f() {
    std::cout << "A<T, 2>::f()" << std::endl;
}

template<class T>
void A<T, 2>::g() {
    std::cout << "A<T, 2>::g()" << std::endl;
}

template<class T>
void A<T, 2>::h() {
    std::cout << "A<T, 2>::h()" << std::endl;
}

// explicit (full) specialization of a member of partial specialization
template<>
void A<char, 2>::h() {
    std::cout << "A<char, 2>::h() (Full)" << std::endl;
}

///////////////////////////////////////////////////////////////////////
// partial specialization withing another template class
template<class T>
struct B {
    template<class T2>
    struct C {
        C() {
            std::cout << "B<T>::C<T2> primary template" << std::endl;
        }
    }; // primary template
    template<class T2>
    struct C<T2*> {
        C() {
            std::cout << "B<T>::C<T2*> member partial specialization" << std::endl;
        }
    }; // partial specialization
};

template<>
template<class T2>
struct B<short>::C {
    C() {
        std::cout << "B<short>::C<T2> full specialization" << std::endl;
    }
}; // full specialization of primary member template

template<>
template<>
struct B<char>::C<char*> {
    C() {
        std::cout << "B<T>::C<char*> full specialization of member partial specialization" << std::endl;
    }
}; // full specialization of member partial specialization

int main(int argc, char* argv[])
{
    A<char, 0> a1;
    A<char, 2> a2;

    a1.f();

    a2.g();
    a2.h();
    a2.f();

    ////////////////////////////////////////////
    B<char>::C<int*> c1;
    B<short>::C<int*> c2;
    B<char>::C<int> c3;
    B<char>::C<char*> c4;
    B<short>::C<char*> c5;
}
