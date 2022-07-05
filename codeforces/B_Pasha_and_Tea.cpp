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
    int n, w;
    cin >> n >> w;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    double l = 0, h = w;
    while (l < h) {
        double mid = (l + h) / 2;

        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            if (arr[i] < mid) flag = false;
        }
        for (int i = n; i < 2 * n && flag; i++) {
            if (arr[i] < 2 * mid) flag = false;
        }

        if (flag && (3 * mid * n) <= w) {
            l = mid + pow(10, -12);
        } else {
            h = mid - pow(10, -12);
        }
    }

    double ans = 3 * h * n;
    cout.precision(10);
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