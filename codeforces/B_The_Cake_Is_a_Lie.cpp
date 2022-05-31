#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool solve(ll n, ll m, ll i, ll j, ll remaining_k, map<pair<pair<ll, ll>, ll>, bool>& dp) {
    if (remaining_k < 0) {
        return false;
    } else {
        pair<pair<ll, ll>, ll> key = make_pair(make_pair(i, j), remaining_k);
        if (i <= n && j <= m) {
            if (i == n && j == m) {
                return remaining_k == 0;
            } else {
                if (dp.count(key)) {
                    return dp[key];
                } else {
                    dp[key] = solve(n, m, i + 1, j, remaining_k - j, dp) || solve(n, m, i, j + 1, remaining_k - i, dp);
                }
                return dp[key];
            }
        } else {
            return false;
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;

        map<pair<pair<ll, ll>, ll>, bool> dp;
        cout << (solve(n, m, 1, 1, k, dp) ? "YES" : "NO") << endl;
    }
}

// correct