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

    vector<int> pre(n);
    for (int i = 1; i < n - 1; i++) {
        pre[i] = pre[i - 1] + ((arr[i - 1] >= arr[i]) && (arr[i] >= arr[i + 1]));
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (r - l <= 1) {
            cout << (r - l + 1) << endl;
            continue;
        }
        l--, r--;

        cout << (r - l + 1) - (pre[r - 1] - pre[l]) << endl;
    }
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}