#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// sealing base class with final keyword will not let it be inherited.
class Base final {
   public:
    virtual void print_something() {
        cout << "I am base class." << endl;
    }
};

// class Child : public Base {
//    public:
//     void print_something() {
//         cout << "I am child class." << endl;
//     }
// };

int32_t main() {
    // Base *base_pointer;
    // Child child;
    // base_pointer = &child;

    // base_pointer->print_something();
}