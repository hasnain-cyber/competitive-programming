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

int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << -arr[0] << endl;
        return;
    }

    cout << "1 1" << endl;
    cout << -arr[0] << endl;
    cout << "1 " << n << endl;
    cout << 0 << " ";
    for (int i = 2; i <= n; i++) {
        cout << -n * arr[i - 1] << " ";
    }
    cout << endl;
    cout << "2 " << n << endl;
    for (int i = 2; i <= n; i++) {
        cout << (n - 1) * arr[i - 1] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}