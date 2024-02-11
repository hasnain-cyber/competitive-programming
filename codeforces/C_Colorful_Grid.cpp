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
    int n, m, k;
    cin >> n >> m >> k;

    if (n + m - 2 > k || (n + m - 2) % 2 != k % 2) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if ((i + j) & 1) cout << "R ";
            else cout << "B ";
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) cout << "R ";
            else cout << "B ";
        }
        cout << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}