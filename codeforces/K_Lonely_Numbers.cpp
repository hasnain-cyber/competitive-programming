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
void solve_testcase() {
    int n;
    cin >> n;

    cout << dp[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 1e6;
    dp = vector<int>(N + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (i & 1) {
            double temp = sqrt(i);
            if (temp == (int)temp) {
                dp[i] = dp[i - 1] - 1;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        } else {
            dp[i] = dp[i - 1];
        }
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}