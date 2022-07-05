#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll find_max_element(vector<vector<ll>> &arr, ll i1, ll i2, ll j1, ll j2) {
    ll ans = MIN;
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            ans = max(ans, arr[i][j]);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> arr(n, vector<ll>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        ll max_value = MIN;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                max_value = max(max_value, arr[i][j]);
            }
        }

        ll ans = MAX;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (arr[i][j] == max_value) {
                    ll value1 = max(i + 1, n - i), value2 = max(j + 1, m - j);
                    ans = min(value1 * value2, ans);
                }
            }
        }

        cout << ans << endl;
    }
}