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

int rec(vector<int>& counter, int i, int mex, vector<vector<int>> &dp) {
    if (i == 0) return (counter[0] - 1) * mex;
    if (dp[i][mex] != -1) return dp[i][mex];

    int ans = (counter[i] - 1) * mex + i + rec(counter, i - 1, i, dp);
    ans = min(ans, rec(counter, i - 1, mex, dp));

    return dp[i][mex] = ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> counter(n, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= n) continue;
        counter[arr[i]]++;
    }

    int mex = n;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            mex = i;
            break;
        }
    }

    if (mex == 0) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << rec(counter, mex - 1, mex, dp) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}