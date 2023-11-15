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

int solve(int n, int m, int x1, int y1, int x2, int y2, int direction, vector<vector<vector<bool>>>& visited) {
    if (visited[x1][y1][direction]) return INT_MAX;
    visited[x1][y1][direction] = true;

    if (direction == 0) {
        if (x1 - x2 >= 0 && y1 - y2 >= 0 && x1 - x2 == y1 - y2) return 0;

        int d1 = x1, d2 = y1;
        if (d1 < d2) {
            return 1 + solve(n, m, 0, y1 - d1, x2, y2, 1, visited);
        }
        else if (d2 < d1) {
            return 1 + solve(n, m, x1 - d2, 0, x2, y2, 2, visited);
        }
        else {
            return 1 + solve(n, m, 0, 0, x2, y2, 3, visited);
        }
    }
    else if (direction == 1) {
        if (x2 - x1 >= 0 && y1 - y2 >= 0 && x2 - x1 == y1 - y2) return 0;

        int d1 = (m - 1) - x1, d2 = y1;
        if (d1 < d2) {
            return 1 + solve(n, m, m - 1, y1 - d1, x2, y2, 0, visited);
        }
        else if (d2 < d1) {
            return 1 + solve(n, m, x1 + d2, 0, x2, y2, 3, visited);
        }
        else {
            return 1 + solve(n, m, m - 1, 0, x2, y2, 2, visited);
        }
    }
    else if (direction == 2) {
        if (x1 - x2 >= 0 && y2 - y1 >= 0 && x1 - x2 == y2 - y1) return 0;

        int d1 = x1, d2 = (n - 1) - y1;
        if (d1 < d2) {
            return 1 + solve(n, m, 0, y1 + d1, x2, y2, 3, visited);
        }
        else if (d2 < d1) {
            return 1 + solve(n, m, x1 - d2, n - 1, x2, y2, 0, visited);
        }
        else {
            return 1 + solve(n, m, 0, n - 1, x2, y2, 1, visited);
        }
    }
    else {
        if (x2 - x1 >= 0 && y2 - y1 >= 0 && x2 - x1 == y2 - y1) return 0;

        int d1 = (m - 1) - x1, d2 = (n - 1) - y1;
        if (d1 < d2) {
            return 1 + solve(n, m, m - 1, y1 + d1, x2, y2, 2, visited);
        }
        else if (d2 < d1) {
            return 1 + solve(n, m, x1 + d2, n - 1, x2, y2, 1, visited);
        }
        else {
            return 1 + solve(n, m, m - 1, n - 1, x2, y2, 0, visited);
        }
    }
}

void solve_testcase() {
    int n, m, x1, y1, x2, y2;
    string direction;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2 >> direction;
    x1--, y1--, x2--, y2--;

    int d = 0;
    if (direction == "UR") d = 1;
    else if (direction == "DL") d = 2;
    else if (direction == "DR") d = 3;

    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4, false)));
    int ans = solve(n, m, x1, y1, x2, y2, d, visited);
    if (ans >= INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}