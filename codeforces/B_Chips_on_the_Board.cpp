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
    vector<int> arr1(n), arr2(n);
    int s1 = 0, s2 = 0, min_value1 = infinity, min_value2 = infinity;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        s1 += arr1[i];
        min_value1 = min(min_value1, arr1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
        s2 += arr2[i];
        min_value2 = min(min_value2, arr2[i]);
    }

    int ans = min(min_value1 * n + s2, min_value2 * n + s1);
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}