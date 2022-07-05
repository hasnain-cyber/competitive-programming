#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int solve(vector<int> &arr, int i, int j, int m, int k) {
    if (m == 1)
        return max(arr[i], arr[j]);

    if (k > 0) {
        int value1 = max(solve(arr, i + 1, j, m - 1, k - 1), solve(arr, i, j - 1, m - 1, k - 1));
        int value2 = min(solve(arr, i + 1, j, m - 1, k), solve(arr, i, j - 1, m - 1, k));
        return max(value1, value2);
    } else {
        int value2 = min(solve(arr, i + 1, j, m - 1, k), solve(arr, i, j - 1, m - 1, k));
        return value2;
    }
}

void solve_testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(arr, 0, n - 1, m, k) << endl;
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