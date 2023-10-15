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

    string ans = "a";
    map<string, int> mp;
    for (int i = 1; i < n; i++) {
        char to_add = 'a';
        for (char ch = 'b'; ch <= (char)('a' + k - 1); ch++) {
            string curr = string(1, ans.back());
            curr.push_back(to_add);
            
            string temp = string(1, ans.back());
            temp.push_back(ch);
            if (mp[temp] < mp[curr]) to_add = ch;
        }

        ans.push_back(to_add);
        mp[ans.substr(ans.size() - 2, 2)]++;
    }

    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
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