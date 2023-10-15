#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

int find_reverse(vector<int>& a, vector<int>& b, int i, int j, vector<vector<int>>& dp) {
    if (i == j) return a[i] * b[i];
    if (i == j - 1) return a[i] * b[i + 1] + b[i] * a[i + 1];
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = find_reverse(a, b, i + 1, j - 1, dp) + a[i] * b[j] + a[j] * b[i];
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> pre(n);
    pre[0] = a[0] * b[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + (a[i] * b[i]);

    int ans = pre[n - 1];
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int value = (i > 0 ? pre[i - 1] : 0) + (pre[n - 1] - pre[j]) + find_reverse(a, b, i, j, dp);
            ans = max(ans, value);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}