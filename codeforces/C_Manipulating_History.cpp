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
    map<char, int> mp;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;

        for (char ch : s) mp[ch]++;
    }
    string s;
    cin >> s;
    for (char ch : s) mp[ch]++;

    for (auto it : mp) {
        if (it.second & 1) {
            cout << it.first << endl;
            return;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}