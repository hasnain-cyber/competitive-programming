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
        ll a[n];
        for (ll i = 0; i < n; i++) cin >> a[i];

        map<ll, ll> m;
        for (ll i = 0; i < n; i++) {
            m[a[i]]++;
        }

        ll ans = 0;
        for (auto it : m) {
            if (!(it.second & 1)) {
                ans += it.second / 2;
            }
        }

        if (ans > 0) {
            for (auto it : m) {
                if (it.second & 1) {
                    ans += it.second / 2 + 1;
                }
            }
        } else {
            bool one_flag = true;
            for (auto it : m) {
                if (it.second != 1) {
                    one_flag = false;
                    break;
                }
            }

            if (one_flag) {
                ans += m.size() + 1;
            } else {
                ans += m.size();
            }
        }

        cout << ans << endl;
    }
}