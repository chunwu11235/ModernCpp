#include<iostream>
#include "my_lib.h"

using namespace std;

int my_add(int a, int b) {
    return a + b;
}

int Add(const int *a, const int *b) {
    return *a + *b;
}

void AddVal(const int *a, const int *b, int *result) {
    *result = *a + *b;
}

void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result) {
    int ans = 1;
    for(;*a > 1; *a -= 1) {
        ans *= *a;
    }
    *result = ans;
}

void play_with_pointers() {
    // uniform initialization'
    int a{10};
    cout << a << "\t" << &a << "\n";

    int a_ref{a};
    cout << a_ref << "\t" << &a_ref << "\n";
    
    // basic overpation of pointers
    int *a_ptr{&a};
    cout << a_ptr << "\t" << *a_ptr << "\n";

    // nullptr
    int *a_ptr2 = nullptr; // always use nullptr;
    // *a_ptr2 = 100; // cannot read and write a nullptr
    a_ptr2 = &a; // need to assign address first
    *a_ptr2 = 5;
    cout << a << "\n";

    cout << *a_ptr2 << "\n";

    *a_ptr = 5; // same as &a = 5, same as a = 5
    cout << a << "\n";

    int arr[]{1,2,3,4,5};
    cout << arr << "\t" << arr[2] << "\n";
    int *arr_ptr = arr;
    cout << arr_ptr << "\t" << arr_ptr[3] << "\n";

    // void pointer
    void *ptr = &a;
    char *c_ptr = new char{'c'};
    cout << (void * ) &c_ptr << "\t" << *c_ptr << endl; // void * to print the address of char ptr

    // ptr of a ptr
    // ptr is a object that holds the address of another object
    int num = 1123;
    int *n_ptr = &num;
    cout << n_ptr << "\t"<< &n_ptr << "\n";
    *n_ptr = 100; // assign 100 to the address of n_ptr
    cout << n_ptr << "\n"; // address should be the same
    
    // since ptr itself is a object, we can have ptr to ptr
    int **n_pptr = &n_ptr;
    cout << n_pptr << "\t"<< &n_ptr << "\n"; // should be the same

    int *&n_ptr_ref{n_ptr};
    cout << n_ptr_ref << "\t" << n_ptr << "\n";

    n_ptr_ref = &a; // this is OK, all point to a
    cout << &a << "\t" << n_ptr_ref << "\t" << n_ptr << 
    "\t" << *n_pptr << "\n";
    
    cout << a << "\n"; // sould still be 5
    *n_ptr_ref = 50; // a shold be 50
    cout << a << "\t";
    **n_pptr = 101; // a should be 101
    cout << a << "\t";


    cout << "\n";
}
void play_with_reference() {
    int x = 10;
    int &x_ref = x;

    // int &ref = 10; // not allow, must bind to a variable not a literal
    cout << &x << "\t" << &x_ref; // same address, x and x_ref are identifiers

    cout << "\n";
}
void pass_function_arguments() {

    // local function
    int *ptr = new int{10};
    cout << ptr << "\t" << &ptr << "\t" << *ptr;
    
    // c++ doesn't support local function
    // we need to use the lambda feature in modern c++ (11/14/17)
    auto local_function = [] (int *ptr_local) {
        // the values of ptr and ptr_local are the same
        // but the addresses are not, ptr_local and ptr are two different variables!
        // pass by value in this case
        cout << ptr_local << " address of the local ptr: " << &ptr_local 
            << "\t" << *ptr_local << "\n";

        int *&ptr_local_ref = ptr_local;
        ptr_local_ref = new int{10000}; // ptr_local now point to 10000;

        // we have changed the value of ptr_loca
        cout << "this has changed " << ptr_local << " address of the local ptr: " << &ptr_local
            << "\t" << *ptr_local << "\n";

    };

    local_function(ptr);       
    // nothign has changed for ptr
    cout << ptr << "\t" << &ptr << "\t" << *ptr;
    cout <<"\n";
}

void play_with_const() {

    // ref to const 
    const int n = 10;
    int n2 = n; // this is OK, copy value
    const int &ref_to_const = n;
    // int &ref = n; // not allow
    
    int num = 10;
    int *ptr = &num;
    cout << ptr << "\t" << &ptr << "\t" << *ptr << "\n"; 
    
    // what is the difference?
    const int *ptr_to_const = ptr; // pointer to a const int
    *ptr = 100; // allow
    // *ptr_to_const = 1000; // not allow
    
    cout << ptr << "\t" << &ptr << "\t" << *ptr << "\n"; 
    cout << ptr_to_const << "\t" << &ptr_to_const << "\t" << *ptr_to_const << "\n"; 

    ptr_to_const = new int{123}; // ptr_to_const itself is not const, it is the stuff it points to a const.
    cout << ptr_to_const << "\t" << &ptr_to_const << "\t" << *ptr_to_const << "\n"; 
    

    int const *ptr_to_const2 = ptr; // the same as ptr_to_const
    cout << ptr_to_const2 << "\t" << &ptr_to_const2 << "\t" << *ptr_to_const2 << "\n"; 
    // *ptr_to_const2 = 13; // not allow
    ptr_to_const2 = new int{321}; // allow
    cout << ptr_to_const2 << "\t" << &ptr_to_const2 << "\t" << *ptr_to_const2 << "\n"; 
    
    
    // const pointer
    const int const_int = 2;
    // int *const const_ptr = &const_int; // not allow
    int *const const_ptr = ptr; // const pointer to int
    *const_ptr = 1231; // OK

    // const_ptr = &const_int; // not allow
    const int *const const_ptr_to_const =  &const_int; // OK

    cout << ptr << "\t" << &ptr << "\t" << *ptr << "\n"; 
    cout << const_ptr << "\t" << &const_ptr << "\t" << *const_ptr << "\n"; 

    // mix all
    int x = 5 ;
    const int *ptr1 = &x ;
    const int *&p_ref1 = ptr1 ;

    int *const ptr2 = &x;
    const int *const &p_ref2 = ptr2; // attention!   
}

