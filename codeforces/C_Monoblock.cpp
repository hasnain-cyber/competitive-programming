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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += (arr[i] != arr[i - 1]) * i * (n - i);
    }

    for (int i = 0; i < q; i++) {
        int idx, x;
        cin >> idx >> x;
        idx--;

        if (idx > 0) ans -= (arr[idx] != arr[idx - 1]) * idx * (n - idx);
        if (idx < n - 1) ans -= (arr[idx + 1] != arr[idx]) * (idx + 1) * (n - (idx + 1));
        arr[idx] = x;
        if (idx > 0) ans += (arr[idx] != arr[idx - 1]) * idx * (n - idx);
        if (idx < n - 1) ans += (arr[idx + 1] != arr[idx]) * (idx + 1) * (n - (idx + 1));

        cout << ans + n * (n + 1) / 2 << endl;
    }
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}