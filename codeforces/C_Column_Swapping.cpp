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
        ll arr[n][m];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) cin >> arr[i][j];
        }

        bool flag = true;
        pair<ll, ll> ans;
        for (ll i = 0; i < n && flag; i++) {
            for (ll j = 0; j < m - 1 && flag; j++) {
                if (arr[i][j] > arr[i][j + 1]) {
                    ans.first = j;
                    while (j < m - 1 && arr[i][j] > arr[i][j + 1]) {
                        // swap two columns
                        for (ll k = 0; k < n; k++) swap(arr[k][j], arr[k][j + 1]);
                        j++;
                    }
                    flag = false;
                    ans.second = j;
                }
            }
        }

        if (flag)
            cout << "1 1" << endl;
        else {
            bool flag = true;
            for (ll i = 0; i < n && flag; i++) {
                for (ll j = 0; j < m - 1 && flag; j++) {
                    if (arr[i][j] > arr[i][j + 1]) {
                        flag = false;
                    }
                }
            }

            if (flag)
                cout << ans.first + 1 << " " << ans.second + 1 << endl;
            else
                cout << -1 << endl;
        }
    }
}

// correct