#include <iostream>
#include "Oop.h"


Base::Base() {
    std::cout << "Base()\n";
}

Base::Base(int n_private, int n_protected): n_private{n_private}, n_protected{n_protected} {
    std::cout << "Base(int, int)\n";
}

Base::~Base() {
    std::cout << "~Base()\n";
}

void Base::show() const{
    std::cout << "Base::show()\n";
    std::cout << n_private << "\t" << n_protected << "\n";
}

void Base::func() const{
    std::cout << "Base::func()\n";
}

Derived::Derived() {
    std::cout << "Derived()\n";
}

Derived::Derived(int n_derived): n_derived{n_derived} {
    std::cout << "Derived(int)\n";
}

Derived::Derived(int n_derived, int n_private, int n_protected): Base(n_private, n_protected) {
    // Base(n_private, n_protected); // no, need to use memebr initialization
    std::cout << "Derived(int, int, int)\n";
    this->n_derived = n_derived;
} 

Derived::~Derived() {
    std::cout << "~Derived()\n";
}

void Derived::show() const {
    std::cout << "Derived::show()\n";
    Base::show();
    std::cout << n_derived << "\n"; // cannot see n_private
}

void Derived::func() const{
    std::cout << "Derived::func()\n";
}

void demo_oop() {
    std::cout << "--- oop\n";

    std::cout << "---\n";
    // see the order of constructors and destructors
    Derived d1;

    std::cout << "---\n";
    Derived d2{10}; // still invoke Base()

    std::cout << "---\n";
    Derived d3{1, 2, 3};
    d3.show();

    std::cout << "--- virtual\n";
    // runtime polymorphism can only be achieved by using pointers and references
    Base* b1 = new Derived{};
    b1->func(); // Derived::func()
    delete b1; // ~Base()

    std::cout << "--- virtual\n";
    // we don't have runtime polymorphism with value types
    Base b2;
    b2 = Derived{1,2,3};
    b2.show(); // Base::show()
    b2.func(); // Base::func() !!!!

    std::cout << "--- virtual\n";
    const Base& b3 = Derived{2,3,4};
    b3.show(); // Base::show()
    b3.func(); // Derived::func() !!!!


    std::cout << "--- end\n";
}