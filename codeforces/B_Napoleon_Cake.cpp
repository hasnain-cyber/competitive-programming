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

        ll ans[n];
        ll current_charge = 0;
        for (int i = n - 1; i >= 0; i--) {
            current_charge = max(current_charge, arr[i]);
            if (current_charge > 0) {
                current_charge -= 1;
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }

        for (ll i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}

// correct