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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }

    while (i < n) ans.push_back(a[i++]);
    while (j < m) ans.push_back(b[j++]);

    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}