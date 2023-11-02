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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> v1, v2;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            v1.push_back((arr[i] + arr[i + 1]) / 2);
        }
        else if (arr[i] > arr[i + 1]) {
            v2.push_back((arr[i] + arr[i + 1] + 1) / 2);
        }
    }

    int mn = 1e9, mx = 0;
    for (auto ele : v1) mn = min(mn, ele);
    for (auto ele : v2) mx = max(mx, ele);

    if (mn >= mx) {
        cout << mn << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}