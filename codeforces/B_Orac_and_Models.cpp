#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int solve(const vector<int> &arr, int i, int n, map<int, int> &dp) {
    if (dp.count(i)) return dp[i];

    int ans = 0;
    for (int factor = 2; factor * i <= n; factor++) {
        if (arr[factor * i - 1] > arr[i - 1]) {
            if (!dp.count(factor * i)) dp[factor * i] = solve(arr, factor * i, n, dp);
            ans = max(ans, dp[factor * i]);
        }
    }

    dp[i] = 1 + ans;
    return dp[i];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> dp;
        cout << solve(arr, 1, n, dp) << endl;
    }
}