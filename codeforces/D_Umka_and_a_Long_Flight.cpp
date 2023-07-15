#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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

vector<int> dp;
int nth_fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return dp[n] = nth_fibonacci(n - 1) + nth_fibonacci(n - 2);
}

bool solve(vector<vector<bool>> &blocked, int n, int m, int current) {
    // cout << "current: " << current << endl;
    if (current == 0) {
        return true;
    }

    // find a unblocked square with side length current, and block it and solve for current - 1
    int square_side = nth_fibonacci(current);
    // cout << "square_side: " << square_side << endl;
    for (int i = 0; i < n - square_side + 1; i++) {
        for (int j = 0; j < m - square_side + 1; j++) {
            bool is_blocked = false;
            for (int k = i; k < i + square_side; k++) {
                for (int l = j; l < j + square_side; l++) {
                    if (blocked[k][l]) {
                        is_blocked = true;
                        break;
                    }
                }
                if (is_blocked) {
                    break;
                }
            }

            // cout << "i, j: " << i << ", " << j << endl;
            // cout << "is_blocked: " << is_blocked << endl;

            if (!is_blocked) {
                for (int k = i; k < i + square_side; k++) {
                    for (int l = j; l < j + square_side; l++) {
                        blocked[k][l] = true;
                    }
                }
                if (solve(blocked, n, m, current - 1)) {
                    return true;
                } else {
                    // unblock the blocked squares, and proceed
                    for (int k = i; k < i + square_side; k++) {
                        for (int l = j; l < j + square_side; l++) {
                            blocked[k][l] = false;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void solve_testcase() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<bool>> blocked(nth_fibonacci(n), vector<bool>(nth_fibonacci(n + 1), false));
    blocked[x - 1][y - 1] = true;

    if (solve(blocked, blocked.size(), blocked[0].size(), n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp = vector<int>(50, -1);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}