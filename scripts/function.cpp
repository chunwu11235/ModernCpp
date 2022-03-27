#include "stdio.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello!" << endl;

    // functions and function objects
    auto func_obj1 = [](int a, int b){
        cout << "Lambda Function" << endl;
        return a+b;
        };

    cout << func_obj1(10, 20) << endl;

    struct AddFunc{
        int operator()(int a, int b) const{
            cout << "Func Object" << endl;
            return a+b;
        }
    };

    auto func_obj2 = AddFunc();
    cout << func_obj2(100, 22) << endl;

    return 0;
}