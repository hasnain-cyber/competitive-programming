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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];

        map<ll, ll> mp;
        for (ll i = 0; i < n; i++) mp[a[i]] = i;

        ll ans = MAX;
        for (ll i = 0; i < n; i++) {
            set<ll> remove_values;
            for (auto it : mp) {
                if (it.first < b[i]) {
                    ans = min(ans, i + it.second);
                    remove_values.insert(it.first);
                } else
                    break;
            }

            for (auto element : remove_values) mp.erase(element);
        }

        cout << ans << endl;
    }
}