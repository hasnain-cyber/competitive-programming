#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class Base {
   public:
    virtual void print_something() {
        cout << "I am base class." << endl;
    }
};

class Child : public Base {
   public:
    void print_something() {
        cout << "I am child class." << endl;
    }
};

int32_t main() {
    Base *base_pointer;
    Child child;
    base_pointer = &child;

    base_pointer->print_something();
}