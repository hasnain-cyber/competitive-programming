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
    int n, m;
    cin >> n >> m;

    n %= m;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    else if (m % n == 0) {
        int quotient = m / n;
        if (__builtin_popcount(quotient) == 1) {
            cout << (quotient - 1) * n << endl;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    else if (__builtin_popcount(m) == 1) {
        int ans = 0;
        int k = log2(m);
        for (int i = 0; i < 64; i++) {
            if (((n >> i) & 1) == 1) {
                ans += (1LL << i) * ((1LL << (k - i)) - 1);
            }
        }

        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
        return;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}