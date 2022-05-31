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
        ll s = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }

        ld k = 2 * s / (ld)n;
        if (k != (ll)k) {
            cout << 0 << endl;
        } else {
            map<ll, ll> mp;
            for (ll i = 0; i < n; i++) {
                mp[arr[i]]++;
            }

            ll m = mp.size();
            vector<ll> keys;
            for (auto it : mp) {
                keys.push_back(it.first);
            }
            sort(keys.begin(), keys.end());

            ll ans = 0;
            // using two different keys.
            ll l = 0, r = m - 1;
            while (l < r) {
                ll check_sum = keys[l] + keys[r];
                if (check_sum < k) {
                    l++;
                } else if (check_sum > k) {
                    r--;
                } else {
                    ans += (mp[keys[l]]) * (mp[keys[r]]);
                    l++;
                    r--;
                }
            }

            // using a single key;
            for (ll i = 0; i < m; i++) {
                ll key = keys[i];
                ll count = mp[key];
                if (2 * key == k) {
                    ans += (count * (count - 1)) / 2;
                }
            }

            cout << ans << endl;
        }
    }
}

// correct