#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, g, b;
        cin >> n >> g >> b;

        int ans = 0;
        int needed_good_road = ceil(n / 2.0);
        ans += (needed_good_road / g) * (g + b);

        if (needed_good_road % g == 0)
            ans -= b;
        else
            ans += needed_good_road % g;

        // to prevent cases like 1, 1, 1
        cout << max(ans, n) << endl;
    }
}