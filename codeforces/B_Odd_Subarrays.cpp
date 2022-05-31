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
        for (ll i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) ans++, i++;
        }

        cout << ans << endl;
    }
}