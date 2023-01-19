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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr = arr[i][j];
            int i2 = i - 1, j2 = j - 1;
            while (i2 >= 0 && j2 >= 0) {
                curr += arr[i2][j2];
                i2--;
                j2--;
            }
            i2 = i + 1, j2 = j + 1;
            while (i2 < n && j2 < m) {
                curr += arr[i2][j2];
                i2++;
                j2++;
            }
            i2 = i + 1, j2 = j - 1;
            while (i2 < n && j2 >= 0) {
                curr += arr[i2][j2];
                i2++;
                j2--;
            }
            i2 = i - 1, j2 = j + 1;
            while (i2 >= 0 && j2 < m) {
                curr += arr[i2][j2];
                i2--;
                j2++;
            }

            ans = max(ans, curr);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}