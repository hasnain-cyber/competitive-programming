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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        map<char, ll> mp;
        for (ll i = 0; i < n; i++) mp[s[i]]++;

        ll counter_pairs = 0, counter_ones = 0;
        for (auto it : mp) {
            counter_pairs += it.second / 2;
            counter_ones += it.second % 2;
        }

        ll ans = 0;
        ans += (counter_pairs / k) * 2;
        counter_ones += (counter_pairs % k) * 2;
        if (counter_ones >= k) ans++;

        cout << ans << endl;
    }
}