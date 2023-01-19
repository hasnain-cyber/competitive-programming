#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

vector<int> cost;
int solve(vector<pii> &arr, int index, int n, int k, vector<vector<int>> &dp) {
    if (index == n) {
        return 0;
    }

    if (dp[index][k] != -1) {
        return dp[index][k];
    }

    if (cost[arr[index].first] <= k) {
        return dp[index][k] = max(arr[index].second + solve(arr, index + 1, n, k - cost[arr[index].first], dp), solve(arr, index + 1, n, k, dp));
    } else {
        return dp[index][k] = solve(arr, index + 1, n, k, dp);
    }
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }

    k = min(k, 12 * n);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    cout << solve(arr, 0, n, k, dp) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cost = vector<int>(1e3 + 1, -1);
    cost[0] = cost[1] = 0;
    vector<int> visited = vector<int>(1e3 + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int ele = q.front();
        q.pop();

        for (int i = 1; i <= ele; i++) {
            int value = ele + ele / i;
            if (value <= 1e3 && !visited[value]) {
                visited[value] = 1;
                cost[value] = cost[ele] + 1;
                q.push(value);
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}