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
    int n, k, b, s;
    cin >> n >> k >> b >> s;

    if (!(s >= b * k && s <= b * k + (k - 1) * n)) {
        cout << -1 << endl;
        return;
    }

    if (n == 1) {
        cout << s << endl;
        return;
    }

    vector<int> ans(n);
    ans[0] = b * k;
    int curr_sum = ans[0];
    for (int i = 1; i < n; i++) {
        ans[i] = min(k - 1, s - curr_sum);
        curr_sum += ans[i];
    }

    if (curr_sum < s) {
        ans[0] += s - curr_sum;
    }

    print_arr(ans);
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