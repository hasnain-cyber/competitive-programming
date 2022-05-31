#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        bool flag = false;
        for (ll a = 0; a <= ceil(n / 2020.0); a++) {
            ld b = (n - 2020 * a) / 2021.0;
            if (b == (ll)b) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}

// correct