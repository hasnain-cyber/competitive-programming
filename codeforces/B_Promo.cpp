#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    ll arr[n];
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    ll prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (ll i = 1; i < n + 1; i++) prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];

    while (q--) {
        ll x, y;
        cin >> x >> y;

        cout << prefix_sum[n - (x - y)] - prefix_sum[n - x] << endl;
    }
}