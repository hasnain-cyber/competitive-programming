#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class Point {
   public:
    int x;
    int y;

    Point(int x1, int y1) : x(x1), y(y1){};
};

int32_t main() {
    Point p1(2, 3);

    // default constructor is called here, to copy an object of the same type, we can define it, or the compiler defines it by default for us.
    Point p2 = p1;
}