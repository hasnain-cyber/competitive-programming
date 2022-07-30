#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class Shape {
   public:
    // pure virtual function.
    virtual void draw() = 0;
};

class Circle : public Shape {
   public:
    void draw() {
        cout << "Draw a circle." << endl;
    }
};

class Rectange : public Shape {
   public:
    void draw() {
        cout << "Draw a rectange." << endl;
    }
};

int32_t main() {
    Circle circle;
    Rectange rectange;

    circle.draw();
    rectange.draw();
}