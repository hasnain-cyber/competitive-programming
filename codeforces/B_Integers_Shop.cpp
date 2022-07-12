#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    int minL = infinity, costL = infinity, maxR = -infinity, costR = infinity, max_len = 0, cost_len = infinity;
    for (int i = 0; i < n; i++) {
        int l, r, c;
        cin >> l >> r >> c;

        if (l < minL) {
            minL = l;
            costL = c;
        } else if (l == minL) {
            costL = min(costL, c);
        }

        if (r > maxR) {
            maxR = r;
            costR = c;
        } else if (r == maxR) {
            costR = min(costR, c);
        }

        // this max_len variable is for singlemost longest ranges.
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            cost_len = c;
        } else if (r - l + 1 == max_len) {
            cost_len = min(c, cost_len);
        }

        int ans = costL + costR;
        if (max_len == maxR - minL + 1) {
            cout << min(ans, cost_len) << endl;
        } else {
            cout << ans << endl;
        }
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