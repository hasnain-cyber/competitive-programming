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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ll j = n - 1;
        while (j >= 0 && s[j] != '1') j--;
        if (j >= 0) {
            ll cost = n - 1 - j;
            if (cost <= k) {
                k -= cost;
                swap(s[j], s[n - 1]);
            }
        }

        ll i = 0;
        while (i <= n - 2 && s[i] != '1') i++;
        if (i <= n - 2) {
            ll cost = i;
            if (cost <= k) {
                k -= cost;
                swap(s[i], s[0]);
            }
        }

        // calculate fs

        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '0')
                ans += 0;
            else if (s[i] == '0' && s[i + 1] == '1')
                ans += 1;
            else if (s[i] == '1' && s[i + 1] == '0')
                ans += 10;
            else
                ans += 11;
        }
        cout << ans << endl;
    }
}