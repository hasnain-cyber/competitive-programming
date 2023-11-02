#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n;
    cin >> n;
    int grid[n][n];
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            grid[i][j] = temp[j] - '0';
        }
    }

    int ans = 0;
    int left[n];
    for (int i = 0; i < n; i++) left[i] = 0;
    int right[n];
    for (int i = 0; i < n; i++) right[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int pre[n];
        pre[0] = left[0] + right[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + left[i] + right[i];
        }

        for (int j = 0; j < n; j++) {
            if ((grid[i][j] + pre[j]) & 1) {
                ans++;
                left[j]++;
                if (j + 1 <= n - 1) right[j + 1]--;
            }
        }

        for (int j = 0; j < n; j++) {
            if (left[j] > 0) {
                if (j - 1 >= 0) {
                    left[j - 1] = (left[j - 1] + left[j]) % 2;
                    left[j] = 0;
                }
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            if (right[j] < 0) {
                if (j + 1 <= n - 1) right[j + 1] = (right[j + 1] + right[j]) % 2;
                right[j] = 0;
            }
        }
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