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

    int min_value = arr[0], counter = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        int val = arr[i] - counter;
        if (val >= min_value) {
            ans += val - min_value;
            counter += val - min_value;
        }
        else {
            ans += min_value - val;
            min_value = val;
        }
    }

    cout << ans + abs(min_value) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}