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

    string temp = "1234567890";
    int cursor = 0;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        // move to desired location
        int idx = temp.find(ch);
        ans += abs(cursor - idx);
        cursor = idx;

        // type it
        ans++;
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