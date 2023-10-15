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
    int n, x, y;
    cin >> n >> x >> y;

    int ans = 0;
    int k1 = (n / x);
    int k2 = (n / y);
    int lcm = (x * y) / __gcd(x, y);
    int k3 = (n / lcm);

    ans += (k1 - k3) * n - (((k1 - k3) - 1) * (k1 - k3)) / 2;
    ans -= ((k2 - k3) * ((k2 - k3) + 1)) / 2;

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}