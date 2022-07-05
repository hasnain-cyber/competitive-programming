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

        ll count = 0;
        for (ll i = 0; i < n; i++) {
            if ((arr[i] & 1) == 0) count++;
        }

        if (count == n) {
            ll min_divisions = MAX;
            for (ll i = 0; i < n; i++) {
                ll divisions = 0;
                while (arr[i] % 2 == 0) {
                    arr[i] /= 2;
                    divisions++;
                }

                min_divisions = min(min_divisions, divisions);
            }

            cout << min_divisions + count - 1 << endl;
        } else {
            cout << count << endl;
        }
    }
}