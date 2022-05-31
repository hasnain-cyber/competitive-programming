#include <math.h>

#include <iostream>

typedef int i16;
typedef long int i32;
typedef long long int i64;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        i64 n;
        cin >> n;

        cout << (n + 1) / 2 << '\n';
    }
}

// correct