#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int solve(int n, int m) {
    if (n == m)
        return 0;
    else if (n > m)
        return 1 + solve(n - 1, m);
    else {
        if (m & 1)
            return min(1 + solve(2 * n, m), 1 + solve(n, m + 1));
        else
            return min(1 + solve(2 * n, m), 1 + solve(n, m / 2));
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;

        cout << solve(n, m) << endl;
    }
}