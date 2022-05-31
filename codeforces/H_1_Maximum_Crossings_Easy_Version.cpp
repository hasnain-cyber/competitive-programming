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

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = i + 1; j < n; j++) {
                if (arr[i] >= arr[j]) ans++;
            }
        }

        cout << ans << endl;
    }
}