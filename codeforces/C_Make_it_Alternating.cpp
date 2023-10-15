#include <bits/stdc++.h>

// #define MOD 1000000007
#define MOD 998244353
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

vector<pair<int, int>> condense(string& s, int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || ans.back().first != (s[i] - '0')) {
            ans.push_back({ s[i] - '0', 1 });
        }
        else {
            ans.back().second++;
        }
    }

    return ans;
}

vector<int> factorial_dp;
int factorial(int n, int mod) {
    if (n == 0) return 1;
    if (factorial_dp[n] != -1) return factorial_dp[n];

    return factorial_dp[n] = (n * factorial(n - 1, mod)) % mod;
}

void solve_testcase() {
    string s;
    cin >> s;
    int n = s.size();

    vector<pair<int, int>> condensed_arr = condense(s, n);
    int ans_combinations = 1, sm = 0;
    for (int i = 0; i < condensed_arr.size(); i++) {
        auto ele = condensed_arr[i];
        ans_combinations = (ans_combinations * ele.second) % MOD;
        sm += ele.second - 1;
    }
    ans_combinations = (ans_combinations * factorial(sm, MOD)) % MOD;
    cout << (n - condensed_arr.size()) << ' ' << ans_combinations << endl;
}

int32_t main() {
    factorial_dp.resize(3 * 1e5, -1);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}