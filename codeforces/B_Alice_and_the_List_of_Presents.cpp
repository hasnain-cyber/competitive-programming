#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int fast_power(int a, int b, int mod = MOD) {
    if (b == 0) return 1;

    if (b & 1)
        return (a * (fast_power(a, b - 1, mod) % mod)) % mod;
    else
        return fast_power((a * a) % mod, b / 2, mod) % mod;
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;

    int ans = fast_power(fast_power(2, m) - 1, n);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}