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
        i64 n, x;
        cin >> n >> x;

        if (x > 3 * n) {
            cout << "NO" << '\n';
            continue;
        } else {
            i64 answer_a, answer_b;
            bool flag = false;
            for (i64 a = x / 3; a <= n; a++) {
                i64 b = 3 * a - x;
                if (b >= 0 && b <= n && 0 <= a + b && a + b <= n) {
                    answer_a = a;
                    answer_b = b;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "YES\n";
                cout << answer_a << " " << answer_b << " " << n - answer_a - answer_b << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }
}

// correct