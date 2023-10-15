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

bool check(int a, int b, int x) {
    if (b < a) swap(a, b);
    if (b < x) return false;
    if (a == x || b == x) return true;
    if (a == 0) return false;

    if (x < a) return check(b % a, a, x);
    else return (b - x) % a == 0;
}

void solve_testcase() {
    int a, b, x;
    cin >> a >> b >> x;

    if (check(a, b, x)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}