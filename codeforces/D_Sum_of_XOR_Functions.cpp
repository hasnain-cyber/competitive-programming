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

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int curr = 0;

        vector<int> pre(n);
        for (int j = 0; j < n; j++) pre[j] = ((arr[j] >> i) & 1);
        for (int j = 1; j < n; j++) pre[j] ^= pre[j - 1];

        int count_0 = 1, count_1 = 0;
        int sum_0 = 0, sum_1 = 0;
        for (int j = 0; j < n; j++) {
            sum_1 += count_1;
            sum_0 += count_0;

            if (pre[j]) count_1++, curr = (curr + sum_0) % MOD;
            else count_0++, curr = (curr + sum_1) % MOD;
        }

        for (int j = 0; j < i; j++) curr = (curr << 1) % MOD;

        ans = (ans + curr) % MOD;
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}