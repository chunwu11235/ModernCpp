#include <iostream>
#include "lib_101.h"
#include "stdio.h"
#include "string"
#include <vector>
#include <memory>

// using namespace My_Function;
using namespace std;

void try_vector() {
    vector<int*> v1;
    v1.emplace_back(new int{10});

    auto v2 = v1;
    *v1[0] = 100;
    cout << *v2[0] << endl;


    vector<int> v3;
    v3.emplace_back(1000);
    auto v4 = v3;
    v4[0] = 1;
    cout << v3[0] << endl;
}

int main(int, char**) {

    signed char c = 128;
    std::cout << (long) c << endl;

    unsigned char c2 = 128;
    std::cout << (long) c2 << endl;

    string test;
    cin >> test;
    cout << test;

    cout << 3/2 << "\t" <<-3/2 << endl;
    cout << (4 <= 10) << endl;
    // try_vector();

    // demo_nested_classes();

    // assignment_sec8();

    // play_with_templates();
    // play_with_overloading();
    // play_with_auto();
    // play_with_pointers();
    // play_with_reference();
    // pass_function_arguments();
    // play_with_const();

}
