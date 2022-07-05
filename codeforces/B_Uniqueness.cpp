#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int dp[2001][2001];
int solve(vector<int> &arr, int i, int j, int n, set<int> &s) {
    if (i > j) return s.size();

    int value1 = s.size(), value2 = s.size();
    if (!s.count(arr[i])) {
        s.insert(arr[i]);
        if (dp[i + 1][j] == -1) dp[i + 1][j] = solve(arr, i + 1, j, n, s);
        value1 = dp[i + 1][j];
        s.erase(arr[i]);
    }
    if (!s.count(arr[j])) {
        s.insert(arr[j]);
        if (dp[i][j - 1] == -1) dp[i][j - 1] = solve(arr, i, j - 1, n, s);
        value2 = dp[i][j - 1];
        s.erase(arr[j]);
    }

    return max(value1, value2);
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    set<int> s;
    for (int i = 0; i < 2001; i++)
        for (int j = 0; j < 2001; j++) dp[i][j] = -1;
    cout << n - solve(arr, 0, n - 1, n, s) << endl;
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