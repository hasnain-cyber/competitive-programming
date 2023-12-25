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

    vector<int> state(n + 1, -1);
    state[0] = 1;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            sz++;
            if (sz <= 1) state[sz] = 1;
            else state[sz] = (state[sz - 1] == 0) ? 0 : -1;
        }
        else if (s[i] == '-') {
            if (state[sz] == 1) {
                if (sz > 0) state[sz - 1] = 1;
            }
            sz--;
        }
        else if (s[i] == '1') {
            if (state[sz] == 0) {
                cout << "NO" << endl;
                return;
            }
            state[sz] = 1;
        }
        else {
            if (state[sz] == 1) {
                cout << "NO" << endl;
                return;
            }
            state[sz] = 0;
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}