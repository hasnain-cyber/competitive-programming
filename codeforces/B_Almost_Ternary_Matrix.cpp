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

    vector<int> r1;
    for (int i = 0; i < m / 2; i++) {
        if (i % 2 == 1) {
            r1.push_back(1);
            r1.push_back(0);
        } else {
            r1.push_back(0);
            r1.push_back(1);
        }
    }

    vector<int> r2;
    for (int i = 0; i < m / 2; i++) {
        if (i % 2 == 0) {
            r2.push_back(1);
            r2.push_back(0);
        } else {
            r2.push_back(0);
            r2.push_back(1);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i % 4 == 0 || i % 4 == 1) {
            for (int i = 0; i < m; i++) {
                cout << r1[i] << " ";
            }
        } else {
            for (int i = 0; i < m; i++) {
                cout << r2[i] << " ";
            }
        }

        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}