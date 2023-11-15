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

    vector<char> ans(n);
    int i = 0, j = n - 1;
    map<char, int> mp;
    for (int i = 0; i < n; i++) mp[s[i]]++;

    // for (char ch = 'a'; ch <= 'z'; ch++) {
    //     while (mp[ch] >= 2) {
    //         ans[i++] = ans[j--] = ch;
    //         mp[ch] -= 2;
    //     }
    // }

    vector<char> curr;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if ((mp[ch] & 1) && curr.size() == 1) {
            ans[i++] = ch;
            mp[ch]--;
            ans[j--] = curr[0];
            curr.clear();
        }

        while (mp[ch] >= 2) {
            ans[i++] = ans[j--] = ch;
            mp[ch] -= 2;
        }
        if (mp[ch]) {
            curr.push_back(ch);
            mp[ch]--;
        }

        // cout << ch << " " << curr.size() << endl;
        if (curr.size() == 1 && ch == 'z') {
            ans[i++] = curr[0];
            curr.clear();
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}