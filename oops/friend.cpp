#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class A {
    private:
    int value = 10;

    // declaring class B as friend, B can now access private data members and functions within itself.
    friend class B;
    // similarly, we can also declare a function as friend.
    friend void print_value(A);
};

class B {
   public:
    void display() {
        A a;
        cout << a.value << endl;
    }
};

void print_value(A a) {
    cout << a.value << endl;
}

int32_t main() {
    B b;
    b.display();

    A a;
    print_value(a);
}