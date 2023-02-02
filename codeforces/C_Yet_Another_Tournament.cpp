#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> temp_arr = arr;
    sort_arr(temp_arr);

    if (temp_arr[0] > m) {
        cout << n + 1 << endl;
        return;
    }

    int max_value = -infinity;
    int x = 0, s = 0;
    for (int i = 0; i < n && s + temp_arr[i] <= m; i++) {
        s += temp_arr[i];
        x++;
        max_value = max(max_value, temp_arr[i]);
    }

    int ans = n - x + 1;
    if (x < n && s - max_value + arr[x] <= m) {
        ans--;
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