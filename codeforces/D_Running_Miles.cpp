#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define ll long long int
#define lld long double

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

    vector<int> pre(n), suf(n);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], arr[i] + i);
    }
    suf[n - 1] = arr[n - 1] - (n - 1);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], arr[i] - i);
    }

    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        ans = max(ans, arr[i] + pre[i - 1] + suf[i + 1]);
    }
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}