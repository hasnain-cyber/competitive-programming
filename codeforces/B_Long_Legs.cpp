#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define ll long long int
#define lld long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int a, b;
    cin >> a >> b;

    int ans = a + b;
    for (int l = 1; l <= 1e5; l++) {
        int value = (l - 1) + ceil(a / (double)l) + ceil(b / (double)l);
        ans = min(ans, value);
    }
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}