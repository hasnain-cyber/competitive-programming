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
    string s, t;
    cin >> s >> t;

    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
        return;
    }

    flag = true;
    for (int i = 0; i < m - 1; i++) {
        if (t[i] == t[i + 1]) {
            flag = false;
            break;
        }
    }

    if (!flag || (t[0] != t[m - 1])) {
        cout << "No" << endl;
        return;
    }

    char check_char = t[0];
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            if (s[i] == check_char) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}