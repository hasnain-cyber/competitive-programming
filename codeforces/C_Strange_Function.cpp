#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

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

int lcm(int x, int y) {
    return (x * y) / __gcd(x, y);
}

void solve_testcase() {
    int n;
    cin >> n;
    int ans = 0, lcm_upto_i_minus_1 = 1;
    for (int i = 2; i <= 50; i++) {
        int occurances = n / lcm_upto_i_minus_1;
        lcm_upto_i_minus_1 = lcm(lcm_upto_i_minus_1, i);
        occurances -= n / lcm_upto_i_minus_1;

        ans = (ans + (occurances * i) % MOD) % MOD;
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