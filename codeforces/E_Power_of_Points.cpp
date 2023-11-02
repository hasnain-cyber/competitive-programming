#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    vector<int> pre(n);
    pre[0] = arr[0].first;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i].first;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int value = n + arr[i].first * (2 * (i + 1) - n) + pre[n - 1] - 2 * pre[i];
        ans[arr[i].second] = value;
    }

    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}