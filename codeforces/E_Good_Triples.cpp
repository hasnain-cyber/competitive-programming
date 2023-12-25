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

int sod(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;

    int ans = 1;
    while (n > 0) {
        int digit = n % 10;
        ans *= ((digit + 1) * (digit + 2)) / 2;
        n /= 10;
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