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
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = s[i] == s[i + 1];
    }

    for (int length = 3; length <= n; length++) {
        for (int i = 0; i + length - 1 < n; i++) {
            int j = i + length - 1;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }

    vector<int> suffix(n);
    int curr = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (dp[i][j]) {
                curr++;
            }
        }
        suffix[i] = curr;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n - 1; j++) {
            if (dp[i][j]) {
                ans += suffix[j + 1];
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}