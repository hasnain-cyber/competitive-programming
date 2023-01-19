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

void solve_testcase() {
    string s;
    cin >> s;

    int n = s.size();
    if (n == 1) {
        cout << stoi(s) - 1 << endl;
        return;
    }

    string s1, s2;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            s2.push_back(s[i]);
        } else {
            s1.push_back(s[i]);
        }
    }

    cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}