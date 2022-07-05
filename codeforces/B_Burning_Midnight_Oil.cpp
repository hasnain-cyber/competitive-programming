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
    int n, k;
    cin >> n >> k;

    int l = 0, h = k * n;
    while (l <= h) {
        int mid = (l + h) / 2;

        // check this value
        int lines_written = 0;
        int value = mid;
        while (value > 0) {
            lines_written += value;
            value /= k;
        }

        if (lines_written < n) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    cout << l << endl;
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