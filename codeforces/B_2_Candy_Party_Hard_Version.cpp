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
    for (int i = 0; i < n; i++) cin >> arr[i];

    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];

    if (s % n) {
        cout << "NO" << endl;
        return;
    }

    int avg = s / n;
    for (int i = 0; i < n; i++) {
        int diff = abs(avg - arr[i]);
        cout << diff << " ";
        // if (__builtin_popcount(diff) > 1) {
        //     cout << "NO" << endl;
        //     return;
        // }
    }
    cout << endl;

    cout << "YES" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}