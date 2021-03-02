# include "lib_primer.h"

void use_auto() {
    // check "decltype" at the same time

    // ex.2.35
    const int i = 42;
    auto j = i; // int
    const auto &k = i; // ref to const int  
    auto *p = &i; // ptr to const int
    const auto j2 = i, &k2 = i; // j2: const int, k2 : ref to const int const int &
}

void use_decltype() {
    // check "auto" at the same time

    int a = 10, &ref = a;
    decltype((a)) ref_to_int = a; // this is an expression
    decltype(a) int1;
    decltype(ref) ref_int = a;

    const int c = 100;
    int *ptr = &a;
    const int *ptr_const = &c;
    decltype(&c) ptr_to_const; // ptr to const int
    decltype(c) const_int = 2; // const int
    decltype((c)) ref_to_const = 423;
    
    decltype(ptr_to_const) ptr_to_const2;
    decltype((ptr_to_const)) ref_ptr_const = &c; // warning is OK
    decltype((ptr_to_const)) ref_ptr_const2 = ptr_const;
    decltype(*ptr_to_const) ref_const_int = c;
    decltype(&ptr_to_const) ptr_ptr_to_const = &ptr_const;

    decltype(ref_to_const) ref_to_const2 = c;
    decltype((ref_to_const)) ref_to_const3 = c;
}


