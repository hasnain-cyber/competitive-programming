#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long
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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> costs(61);
    vector<int> temp_arr = arr;
    for (int bit = 60; bit >= 0; bit--) {
        int cost = 0;
        int temp = (1LL << bit);
        for (int i = 0; i < n; i++) {
            if (temp_arr[i] & temp) continue;

            int transformed = ((2 * temp - 1) & temp_arr[i]);
            cost += temp - transformed;
        }

        costs[bit] = cost;
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;

        int ans = 0;
        for (int bit = 60; bit >= 0; bit--) {
            if (costs[bit] <= k) {
                ans += (1LL << bit);
                k -= costs[bit];
            }
        }

        cout << ans << endl;
    }
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}