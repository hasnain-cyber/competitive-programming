#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    numd distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    cout << ceil(distance / (2 * r)) << endl;
}

// correct