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

vector<int> factors(int n) {
    vector<int> ans;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }

    return ans;
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string ans;
    while (ans.size() < k) ans.push_back(s[0]);

    for (int l = 1; l <= n; l++) {
        string temp = s.substr(0, l);
        while (temp.size() < k) temp += temp;
        temp = temp.substr(0, k);
        ans = min(ans, temp);
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