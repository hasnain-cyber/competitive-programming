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
    string s;
    cin >> s;

    string temp;
    for (int i = 0; i < n; i++) {
        if (s[i] <= s[0]) temp.push_back(s[i]);
        else break;
    }
    s = temp;
    n = s.size();

    int j = 1;
    while (j < n) {
        if (s[0] == s[j]) {
            int i = 1, k = j + 1;
            while (k < n && s[i] == s[k]) i++, k++;

            if (k == n) {
                break;
            }
            else {
                // cout << i << " " << k << endl;
                if (s[i] < s[k]) {
                    break;
                }
                else {
                    j = k;
                }
            }
        }

        j++;
    }

    s = s.substr(0, j);
    string ans = s;
    while (ans.size() < k) ans += ans;
    ans = ans.substr(0, k);

    cout << ans << endl;
}

int32_t main() {
    int t = 1;
    while (t--) {
        solve_testcase();
    }
}