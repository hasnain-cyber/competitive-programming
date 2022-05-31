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
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];

        ll m;
        cin >> m;
        ll shuffle_arr[m];
        for (ll i = 0; i < m; i++) cin >> shuffle_arr[i];

        ll s = 0;
        for (ll i = 0; i < m; i++) s += shuffle_arr[i];
        ll n_cards = s % n;

        cout << arr[n_cards] << endl;
    }
}

// correct