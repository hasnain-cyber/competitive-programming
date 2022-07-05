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
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    map<int, int> sum_rows;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) s += arr[i][j];

        sum_rows[s]++;
    }
    if (sum_rows.size() > 2) {
        cout << -1 << endl;
        return;
    }

    map<int, int> sum_columns;
    for (int j = 0; j < n; j++) {
        int s = 0;
        for (int i = 0; i < n; i++) s += arr[i][j];

        sum_columns[s]++;
    }
    if (sum_columns.size() > 2) {
        cout << -1 << endl;
        return;
    }

    int flag = true;
    if (sum_rows.size() > 1) {
        bool flag2 = false;
        for (auto it : sum_rows) {
            if (it.second == 1) flag2 = true;
        }

        if (!flag2) {
            cout << -1 << endl;
            return;
        } else flag = true;
    }

    if (sum_columns.size() > 1) {
        bool flag2 = false;
        for (auto it : sum_columns) {
            if (it.second == 1) flag2 = true;
        }

        if (!flag2) {
            cout << -1 << endl;
            return;
        } else flag = true;
    }

    if ()
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