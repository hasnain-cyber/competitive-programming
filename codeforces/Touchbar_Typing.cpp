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

int solve(vector<int> &a, int i, int n, int j, vector<vector<int>> &dp, map<int, vector<int>> &prefix, map<int, vector<int>> &suffix) {
    if (i == n) return 0;

    int upper_index = suffix[a[i]][j];
    int lower_index = prefix[a[i]][j];

    int ans;
    if (lower_index != -1 && upper_index != -1) {
        if (dp[i + 1][lower_index] == -1) dp[i + 1][lower_index] = solve(a, i + 1, n, lower_index, dp, prefix, suffix);
        if (dp[i + 1][upper_index] == -1) dp[i + 1][upper_index] = solve(a, i + 1, n, upper_index, dp, prefix, suffix);
        ans = min(abs(j - upper_index) + dp[i + 1][upper_index], abs(j - lower_index) + dp[i + 1][lower_index]);
    } else if (lower_index != -1) {
        if (dp[i + 1][lower_index] == -1) dp[i + 1][lower_index] = solve(a, i + 1, n, lower_index, dp, prefix, suffix);
        ans = abs(j - lower_index) + dp[i + 1][lower_index];
    } else {
        if (dp[i + 1][upper_index] == -1) dp[i + 1][upper_index] = solve(a, i + 1, n, upper_index, dp, prefix, suffix);
        ans = abs(j - upper_index) + dp[i + 1][upper_index];
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        map<int, vector<int>> prefix, prefix_final;
        for (int i = 0; i < m; i++) {
            if (!prefix.count(b[i])) {
                prefix[b[i]] = vector<int>(m, -1);
            }
            prefix[b[i]][i] = i;
        }
        for (auto it : prefix) {
            vector<int> temp = it.second;
            for (int i = 1; i < temp.size(); i++) {
                if (temp[i] == -1) {
                    temp[i] = temp[i - 1];
                }
            }
            prefix_final[it.first] = temp;
        }

        map<int, vector<int>> suffix, suffix_final;
        for (int i = 0; i < m; i++) {
            if (!suffix.count(b[i])) {
                suffix[b[i]] = vector<int>(m, -1);
            }
            suffix[b[i]][i] = i;
        }
        for (auto it : suffix) {
            vector<int> temp = it.second;
            for (int i = temp.size() - 2; i >= 0; i--) {
                if (temp[i] == -1) {
                    temp[i] = temp[i + 1];
                }
            }
            suffix_final[it.first] = temp;
        }

        int ans = infinity;
        vector<vector<int>> dp(n + 1, vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            if (b[i] == a[0]) {
                if (dp[1][i] == -1) dp[1][i] = solve(a, 1, n, i, dp, prefix_final, suffix_final);
                ans = min(ans, dp[1][i]);
            }
        }

        cout << "Case #" << test_case << ": " << ans << endl;
    }
}