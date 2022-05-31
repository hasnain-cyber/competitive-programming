#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c, x, y, z;
        cin >> a >> b >> c;

        z = (c - a) / b + 1;
        x = b * z + a;
        y = b;
        z = c;

        cout << x << " " << y << " " << z << endl;
    }
}

// correct