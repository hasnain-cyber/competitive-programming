#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        vector<ll> sums(n + 1, MIN);
        sums[0] = 0;
        for (ll l = 0; l < n; l++) {
            ll current = 0;
            for (ll r = l; r < n; r++) {
                current += arr[r];
                sums[r - l + 1] = max(sums[r - l + 1], current);
            }
        }

        vector<ll> ans(n + 1, 0);
        for (ll k = 0; k <= n; k++) {
            for (ll i = 0; i <= n; i++) {
                ans[k] = max(ans[k], sums[i] + min(k, i) * x);
            }
        }

        for (auto element : ans) cout << element << " ";
        cout << endl;
    }
}