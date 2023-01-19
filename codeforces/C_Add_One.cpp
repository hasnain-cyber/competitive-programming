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

vector<int> cost;
void solve_testcase() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    while (n > 0) {
        int rem = n % 10;
        n /= 10;
        if (m < 10 - rem) {
            ans++;
            continue;
        }
        ans = (ans + cost[m - (10 - rem)]) % MOD;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 2 * 1e5 + 1;
    cost = vector<int>(N, 0);
    for (int i = 0; i < 9; i++) {
        cost[i] = 2;
    }
    cost[9] = 3;
    for (int i = 10; i < N; i++) {
        cost[i] = (cost[i - 10] + cost[i - 9]) % MOD;
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}