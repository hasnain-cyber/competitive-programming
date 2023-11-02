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

    if (n & 1) {
        cout << -1 << endl;
        return;
    }

    int a = 0, b = 0;
    for (int i = 0; i < 32; i++) {
        int bit1 = ((n >> i) & 1);
        int bit2 = (((n >> 1) >> i) & 1);

        if (bit1 == 1 && bit2 == 1) {
            cout << -1 << endl;
            return;
        }

        if (bit1 == 1 && bit2 == 0) a |= (1 << i);
        else if (bit1 == 0 && bit2 == 1) {
            a |= (1 << i);
            b |= (1 << i);
        }
    }

    cout << a << " " << b << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}