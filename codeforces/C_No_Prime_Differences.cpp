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

void solve_testcase() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> ans;
    if (n > 4) {
        vector<vector<int>> grid(n, vector<int>(m));
        int counter = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = (counter++);
            }
        }
        for (int i = 0; i < n; i += 2) {
            ans.push_back(grid[i]);
        }
        for (int i = 1; i < n; i += 2) {
            ans.push_back(grid[i]);
        }
    }
    else {
        int counter = 1;
        ans = vector<vector<int>>(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = counter++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}