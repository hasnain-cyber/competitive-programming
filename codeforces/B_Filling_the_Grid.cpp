#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int required_width = a[i], required_height = b[j];

            if ((j == required_width && i < required_height) || (i == required_height && j < required_width)) {
                cout << 0 << endl;
                return;
            }

            if (j <= required_width || i <= required_height)
                continue;
            else
                ans = (ans * 2) % MOD;
        }
    }

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