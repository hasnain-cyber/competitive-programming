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

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    } else if (n == 1) {
        for (int i = 0; i < m; i++) cout << i + 2 << " ";
        cout << endl;
    } else if (m == 1) {
        for (int i = 0; i < n; i++) cout << i + 2 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (i + 1) * (n + j + 1) << " ";
            }
            cout << endl;
        }
    }
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