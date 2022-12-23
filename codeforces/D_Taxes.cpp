#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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

int is_prime(int n) {
    if (n == 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve_testcase() {
    int n;
    cin >> n;

    if (is_prime(n)) {
        cout << 1 << endl;
        return;
    }

    if (n & 1) {
        if (is_prime(n - 2)) {
            cout << 2 << endl;
        } else {
            cout << 3 << endl;
        }
    } else {
        if (n == 2) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}