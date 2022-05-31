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
        ll arr[n];

        ll c1 = 0, c2 = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 1) {
                c1++;
            } else {
                c2++;
            }
        }

        ll k = c1 + 2 * c2;
        if (k & 1) {
            cout << "NO" << endl;
        } else {
            k /= 2;

            bool flag = false;
            for (ll x = 0; x <= k; x++) {
                ld y = (k - x) / 2.0;
                if (y == (ll)y && 0 <= x && x <= c1 && 0 <= y && y <= c2) {
                    flag = true;
                    break;
                }
            }

            cout << (flag ? "YES" : "NO") << endl;
        }
    }
}

// correct