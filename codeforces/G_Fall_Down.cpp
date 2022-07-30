#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> count_arr(n, vector<int>(m, 0));
    vector<int> curr(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '*') {
                curr[j]++;
            } else if (arr[i][j] == '.') {
                continue;
            } else {
                count_arr[i][j] = curr[j];
                curr[j] = 0;
            }
        }
    }

    vector<string> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'o') {
                ans[i].push_back('o');
            } else {
                ans[i].push_back('.');
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'o') {
                int count = count_arr[i][j];

                for (int k = i - count; k < i; k++) {
                    ans[k][j] = '*';
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (curr[j] > 0) {
            for (int k = n - curr[j]; k < n; k++) {
                ans[k][j] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
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