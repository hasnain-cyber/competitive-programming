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
        pair<ll, ll> arr[n][m], duplicate_arr[n][m];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                ll value;
                cin >> value;
                arr[i][j] = make_pair(value, j);
                duplicate_arr[i][j] = make_pair(value, j);
            }
        }

        for (ll i = 0; i < n; i++) {
            sort(arr[i], arr[i] + m);
        }

        set<pair<ll, ll>> swap_indices;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (arr[i][j].second != j) {
                    swap_indices.insert(make_pair(min(j, arr[i][j].second), max(j, arr[i][j].second)));
                }
            }
        }

        if (swap_indices.empty()) {
            cout << "1 1" << endl;
        } else if (swap_indices.size() == 1) {
            ll a, b;
            for (auto it : swap_indices) {
                a = it.first;
                b = it.second;
                break;
            }

            bool flag = true;
            for (ll i = 0; i < n; i++) {
                if (duplicate_arr[i][a].first < duplicate_arr[i][b].first) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << a + 1 << " " << b + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}

// correct