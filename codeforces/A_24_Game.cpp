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
    int n;
    cin >> n;

    if (n <= 3) {
        cout << "NO" << endl;
        return;
    } else if (n == 4) {
        cout << "YES" << endl;
        cout << "1 * 2 = 2" << endl;
        cout << "2 * 3 = 6" << endl;
        cout << "6 * 4 = 24" << endl;
    } else if (n == 5) {
        cout << "YES" << endl;
        cout << "5 * 3 = 15" << endl;
        cout << "4 * 2 = 8" << endl;
        cout << "15 + 8 = 23" << endl;
        cout << "23 + 1 = 24" << endl;
    } else {
        cout << "YES" << endl;
        // first make a zero before 4
        cout << "3 - 1 = 2" << endl;
        cout << "2 - 2 = 0" << endl;
        cout << "5 * 0 = 0" << endl;

        for (int i = 7; i <= n; i++) {
            cout << i << " * 0 = 0" << endl;
        }

        cout << "4 * 6 = 24" << endl;
        cout << "24 + 0 = 24" << endl;
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