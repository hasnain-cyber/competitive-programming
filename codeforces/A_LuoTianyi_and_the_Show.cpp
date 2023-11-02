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
    vector<bool> demanded(m, false);
    int counter1 = 0, counter2 = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (value == -1) counter1++;
        else if (value == -2)counter2++;
        else demanded[value - 1] = true;
    }

    vector<int> pre(m), suf(m);
    pre[0] = demanded[0];
    for (int i = 1; i < m; i++) {
        pre[i] = pre[i - 1] + demanded[i];
    }
    suf[m - 1] = demanded[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + demanded[i];
    }

    int ans = min(m, max(counter1 + pre[m - 1], counter2 + pre[m - 1]));
    for (int i = 0; i < m; i++) {
        if (demanded[i]) {
            int value = min(i, (i > 0 ? pre[i - 1] : 0) + counter1) + 1 + min(m - i - 1, (i < m - 1 ? suf[i + 1] : 0) + counter2);
            ans = max(ans, value);
        }
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