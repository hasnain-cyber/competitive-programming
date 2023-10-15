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
    vector<vector<char>> grid(n, vector<char>(m));
    vector<int> r(n, 0), c(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L' || grid[i][j] == 'R' || grid[i][j] == 'U' || grid[i][j] == 'D') {
                r[i]++;
                c[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (r[i] & 1) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (c[i] & 1) {
            cout << -1 << endl;
            return;
        }
    }

    vector<vector<char>> ans(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        int counter = 0;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'U') {
                if (counter & 1) {
                    ans[i][j] = 'W';
                    ans[i + 1][j] = 'B';
                }
                else {
                    ans[i][j] = 'B';
                    ans[i + 1][j] = 'W';
                }
                counter++;
            }
            else if (grid[i][j] == '.') {
                ans[i][j] = grid[i][j];
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'L') {
                if (counter & 1) {
                    ans[i][j] = 'W';
                    ans[i][j + 1] = 'B';
                }
                else {
                    ans[i][j] = 'B';
                    ans[i][j + 1] = 'W';
                }
                counter++;
            }
            else if (grid[i][j] == '.') {
                ans[i][j] = grid[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m;j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}