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

string find_or(string s1, string s2) {
    if (s1.size() < s2.size()) swap(s1, s2);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    while (s2.size() != s1.size()) s2.push_back('0');

    string ans;
    for (int i = 0; i < s1.size(); i++) {
        ans.push_back(max(s1[i], s2[i]));
    }

    while (ans.back() == '0' && ans.size() > 1) ans.pop_back();
    reverse(ans.begin(), ans.end());

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    while (s.back() == '0' && s.size() > 1) s.pop_back();
    n = s.size();
    reverse(s.begin(), s.end());

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') break;
        count++;
    }

    if (count == 0) {
        cout << 0 << endl;
        return;
    }

    string ans;
    for (int i = 0; i + (n - count - 1) < n; i++) {
        if (s[i] == '0') continue;

        string temp;
        for (int j = 0; j < n - count; j++) temp.push_back(s[j + i]);

        // cout << temp << " " << find_xor(s, temp) << endl;
        if (ans.empty() || find_or(s, temp) > ans) ans = find_or(s, temp);
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}