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

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cin >> arr[i][j];
    }

    map<ll, pair<vector<ll>, vector<ll>>> colors;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            colors[arr[i][j]].first.push_back(i);
            colors[arr[i][j]].second.push_back(j);
        }
    }

    ll ans = 0;
    for (auto it : colors) {
        vector<ll> values_x = it.second.first;
        sort(values_x.begin(), values_x.end());

        ll s1 = 0, s2 = 0;
        for (ll i = 0; i < values_x.size(); i++) {
            s1 += i * values_x[i];
            s2 += values_x[i];
        }
        ans += 2 * s1 - (values_x.size() - 1) * s2;

        vector<ll> values_y = it.second.second;
        sort(values_y.begin(), values_y.end());

        s1 = 0, s2 = 0;
        for (ll i = 0; i < values_y.size(); i++) {
            s1 += i * values_y[i];
            s2 += values_y[i];
        }
        ans += 2 * s1 - (values_y.size() - 1) * s2;
    }

    cout << ans << endl;
}