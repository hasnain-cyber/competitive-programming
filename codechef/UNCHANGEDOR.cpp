#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;

        num k = floor(log2(n + 1));
        num ans = pow(2, k) - k - 1;
        if (n >= pow(2, k) + 1) {
            ans += n - pow(2, k);
        }
        cout << ans << endl;
    }
}

// correct