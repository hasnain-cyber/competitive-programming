#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll solve(vector<ll> arr, ll n, ll index, ll count, ll k, ll current) {
    if (count == k) return current;

    ll value1 = MIN, value2 = MIN, value3 = MIN;
    if (index + 1 < n) value1 = solve(arr, n, index + 1, count + 1, k, current + arr[index + 1]);
    if (index - 1 >= 0) value2 = solve(arr, n, index - 1, count + 1, k, current + arr[index - 1]);
    value3 = solve(arr, n, index, count + 1, k, current + arr[index]);

    return max(value3, max(value1, value2));
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr;
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            arr.push_back(temp);
        }

        ll ans = MIN;
        for (ll i = 0; i < n; i++) {
            ll temp = solve(arr, n, i, 0, k, 0);
            ans = max(ans, temp);
        }

        cout << "here: " << ans << endl;
    }
}