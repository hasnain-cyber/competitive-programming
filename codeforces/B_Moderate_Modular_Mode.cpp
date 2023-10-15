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
    int x, y;
    cin >> x >> y;

    int n;
    if (x == y) {
        n = x;
    }
    else if (x > y) {
        n = x + y;
    }
    else {
        int p = x * (y / x);
        n = (p + y) / 2;
    }

    cout << n << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}