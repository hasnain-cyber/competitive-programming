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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int counter = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                counter++;
            else
                ans = (ans + fast_power(2, counter) - 1) % MOD;
        }

        cout << ans << endl;
    }
}