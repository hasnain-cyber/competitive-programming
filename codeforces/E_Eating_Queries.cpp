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
        ll n, q;
        cin >> n >> q;
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);

        ll prefix_sum[n];
        prefix_sum[0] = arr[n - 1];
        for (ll i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i - 1] + arr[n - i - 1];

        while (q--) {
            ll x;
            cin >> x;

            ll index = lower_bound(prefix_sum, prefix_sum + n, x) - prefix_sum;
            if (index == n)
                cout << -1 << endl;
            else
                cout << index + 1 << endl;
        }
    }
}

// correct