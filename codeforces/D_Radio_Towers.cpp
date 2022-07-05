#include <bits/stdc++.h>

// #define MOD 1000000007
#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int divide(int n) {
    if (n == 0) return 1;

    int ans = 0;
    for (int i = 1; i <= n; i += 2) ans = (ans + divide(n - i)) % MOD;

    return ans;
}

int fast_power(int a, int b, int mod) {
    if (b == 0) return 1;

    if (b & 1)
        return (a * (fast_power(a, b - 1, mod) % mod)) % mod;
    else
        return fast_power((a * a) % mod, b / 2, mod) % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    int prefix_sum_odd = 1, prefix_sum_even = 1;
    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            dp[i] = prefix_sum_even % MOD;
            prefix_sum_odd = (prefix_sum_odd + dp[i]) % MOD;
        } else {
            dp[i] = prefix_sum_odd % MOD;
            prefix_sum_even = (prefix_sum_even + dp[i]) % MOD;
        }
    }

    int denominator = fast_power(fast_power(2, n, MOD), (MOD - 2), MOD);
    // this, here is mmi
    cout << ((dp[n] % MOD) * (denominator % MOD)) % MOD << endl;
}