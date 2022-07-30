#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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

int find_best(vector<int> &arr, int x) {
    int ans = infinity;
    for (int i = 0; i < arr.size(); i++) {
        ans = min(ans, abs(arr[i] - x));
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = infinity;

    // 2 connections
    ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, abs(a[n - 1] - b[0]) + abs(a[0] - b[n - 1]));

    // 3 connections
    ans = min(ans, abs(a[0] - b[0]) + find_best(b, a[n - 1]) + find_best(a, b[n - 1]));
    ans = min(ans, abs(a[n - 1] - b[n - 1]) + find_best(b, a[0]) + find_best(a, b[0]));
    ans = min(ans, abs(a[0] - b[n - 1]) + find_best(a, b[0]) + find_best(b, a[n - 1]));
    ans = min(ans, abs(a[n - 1] - b[0]) + find_best(b, a[0]) + find_best(a, b[n - 1]));

    // 4 connections
    int value = find_best(b, a[0]) + find_best(b, a[n - 1]) + find_best(a, b[0]) + find_best(a, b[n - 1]);
    ans = min(ans, value);

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}