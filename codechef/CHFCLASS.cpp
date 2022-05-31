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
        if (n < 6) {
            cout << "0\n";
        } else {
            i64 ans = 1;
            n -= 6;
            ans += floor(n / 7);
            cout << ans << "\n";
        }
    }
}

// correct