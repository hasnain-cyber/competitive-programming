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
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        for (ll i = 0; i < n; i++) cin >> b[i];
        for (ll i = 0; i < n; i++) cin >> c[i];

        map<ll, ll> indices;
        for (ll i = 0; i < n; i++) indices[a[i]] = i;

        ll ans = 1;
        vector<bool> visited(n, false);
        for (ll i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;

            if (c[i] == 0) {
                ll size = 1;
                ll current_index = i;
                while (indices[b[current_index]] != i) {
                    size++;
                    current_index = indices[b[current_index]];
                    visited[current_index] = true;
                    
                    if (c[current_index] != 0) {
                        size = 1;
                        break;
                    }
                }

                if (size > 1) ans = (ans * 2) % MOD;
            }
        }

        cout << ans << endl;
    }
}