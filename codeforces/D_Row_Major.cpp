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

int find_min_distinct(int n) {
    if (n == 1) return 1;
    for (int i = 2; i <= n; i++) {
        if (n % i != 0) return i;
    }

    return n;
}

void solve_testcase() {
    int n;
    cin >> n;

    int mn_distinct_required = find_min_distinct(n);
    string ans;
    int pointer = 0;
    for (int i = 0; i < n; i++) {
        ans.push_back((char)('a' + (pointer++)));
        pointer %= mn_distinct_required;
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