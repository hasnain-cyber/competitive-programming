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
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    // dp will contain the max no. of removals possible strictly to the left of index i.
    vector<int> dp(n, 0);
    vector<int> dp_max(n, -1);
    for (int i = 0; i < n; i++) {
        for (int index : mp[arr[i]]) {
            if (index < i) {
                int temp_ans = (index - 1 >= 0 ? dp[index - 1] : 0) + (i - index + 1);
                dp[i] = max(dp[i], temp_ans);
            } else {
                break;
            }
        }
        if (i - 1 >= 0) {
            dp[i] = max(dp[i - 1], dp[i]);
        }
    }

    cout << dp[n - 1] << endl;
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