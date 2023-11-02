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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    map<char, int> m1, m2;
    for (auto ch : s) m1[ch]++;
    for (auto ch : t) m2[ch]++;

    if (m1 != m2) {
        cout << "NO" << endl;
        return;
    }

    if (n <= 3) {
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
    else if (n == 4) {
        if (s[1] == t[1] && s[2] == t[2]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else if (n == 5) {
        if (s[2] == t[2]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}