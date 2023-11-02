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

int rec(vector<int>& arr, int i, int n, int curr, int k, int mod, vector<vector<int>>& dp) {
    if (i == n) {
        return __builtin_popcount(curr) == k;
    }
    if (dp[i][curr] != -1) return dp[i][curr];

    int ans = rec(arr, i + 1, n, curr, k, mod, dp);
    ans = (ans + rec(arr, i + 1, n, curr & arr[i], k, mod, dp)) % mod;
    return dp[i][curr] = ans;
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0, mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(64, -1));
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        ans = (ans + rec(arr, i + 1, n, curr, k, mod, dp)) % mod;
    }
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}