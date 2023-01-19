#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int gcd = arr[0];
    for (int i = 1; i < n; i++) {
        gcd = __gcd(gcd, arr[i]);
    }

    if (gcd == 1) {
        cout << 0 << endl;
    } else if (__gcd(__gcd(arr[arr.size() - 1], n), gcd) == 1) {
        cout << 1 << endl;
    } else if (__gcd(__gcd(arr[arr.size() - 2], n - 1), gcd) == 1) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}