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
    string s;
    cin >> s;

    vector<int> occur(26, -1);
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (occur[idx] == -1) {
            occur[idx] = i;
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) ans += occur[i] != -1 ? (n - occur[i]): 0;

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}