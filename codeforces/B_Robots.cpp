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
        ll n, m;
        cin >> n >> m;
        char arr[n][m];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) cin >> arr[i][j];
        }

        set<pair<ll, ll>> robot_coordinates;
        ll min_i = MAX, min_j = MAX;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (arr[i][j] == 'R') {
                    robot_coordinates.insert({i, j});
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                }
            }
        }

        if (robot_coordinates.count({min_i, min_j}))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}