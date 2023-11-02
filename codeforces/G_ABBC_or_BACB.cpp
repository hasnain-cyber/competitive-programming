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
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pre(n), suf(n);
    int curr = 0, counter = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') counter++;
        else {
            curr += counter;
            counter = 0;
        }
        pre[i] = curr;
    }

    curr = 0;
    counter = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'A') counter++;
        else {
            curr += counter;
            counter = 0;
        }
        suf[i] = curr;
    }

    int ans = 0;
    for (int i = -1; i < n; i++) {
        int value = (i >= 0 ? pre[i] : 0) + (i < n - 1 ? suf[i + 1] : 0);
        ans = max(ans, value);
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