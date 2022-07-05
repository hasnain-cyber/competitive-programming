#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> arr(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) cin >> arr[i][j];
    }

    ll n_queries;
    cin >> n_queries;

    while (n_queries--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        set<ll> temp;
        for (ll i = y1 - 1; i < y2; i++) {
            for (ll j = x1 - 1; j < x2; j++) {
                temp.insert(arr[j][i]); // ulta de rakha hai question mein
            }
        }

        cout << temp.size() << endl;
    }
}