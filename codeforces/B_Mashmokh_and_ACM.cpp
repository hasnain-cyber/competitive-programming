#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int dp[2001][2001];
int solve(int start, int n, int k) {
    if (dp[start][k] != -1)
        return dp[start][k];
    else if (k == 0)
        return 1;

    int ans = 0;
    for (int j = start; j <= n; j += start) {
        if (dp[j][k - 1] == -1) dp[j][k - 1] = solve(j, n, k - 1) % MOD;
        ans = (ans + dp[j][k - 1]) % MOD;
    }

    dp[start][k] = ans;
    return dp[start][k];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++) dp[i][j] = -1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][k - 1] == -1) dp[i][k - 1] = solve(i, n, k - 1);
        ans = (ans + dp[i][k - 1]) % MOD;
    }

    cout << ans << endl;
}