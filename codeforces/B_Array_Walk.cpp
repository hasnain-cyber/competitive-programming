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
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int t = 0; t <= z; t++) {
        int s = 0;
        for (int i = 0; i <= k - 2 * t; i++) {
            s += arr[i];
        }

        int max_pair = 0;
        for (int i = 0; i + 1 <= min(k - 2 * t + 1, n - 1); i++) {
            max_pair = max(max_pair, arr[i] + arr[i + 1]);
        }

        s += max_pair * t;
        ans = max(ans, s);
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