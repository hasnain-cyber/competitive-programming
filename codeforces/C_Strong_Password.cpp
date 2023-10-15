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

bool rec(vector<vector<int>>& indices, int i, int n, string& l, string& r, int j, int m, vector<vector<int>>& dp) {
    if (j == m) return i >= n;
    if (i != -1 && dp[i][j] != -1) return dp[i][j];

    int low = l[j] - '0';
    int high = r[j] - '0';
    for (int cand = low; cand <= high; cand++) {
        int idx = upper_bound(indices[cand].begin(), indices[cand].end(), i) - indices[cand].begin();
        if (idx == indices[cand].size() || rec(indices, indices[cand][idx], n, l, r, j + 1, m, dp)) return true;
    }

    if (i != -1) dp[i][j] = false;
    return false;
}

void solve_testcase() {
    string s; cin >> s;
    int n = s.size();
    int m; cin >> m;
    string l, r; cin >> l >> r;

    vector<vector<int>> indices(10);
    for (int i = 0; i < n; i++) {
        indices[s[i] - '0'].push_back(i);
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (rec(indices, -1, n, l, r, 0, m, dp)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    // vector<int> arr = { 0, 1, 2, 4 };
    // int idx = upper_bound(arr.begin(), arr.end(), 1) - arr.begin();
    // cout << idx << endl;

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}