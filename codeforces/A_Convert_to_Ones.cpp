#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector<pair<char, int>> arr;
    for (int i = 0; i < n; i++) {
        if (arr.size() == 0) {
            arr.push_back({s[i], 1});
        } else {
            if (arr.back().first == s[i])
                arr.back().second++;
            else
                arr.push_back({s[i], 1});
        }
    }

    int count_zero_groups = 0;
    for (auto ele : arr) {
        if (ele.first == '0') count_zero_groups++;
    }

    if (count_zero_groups == 0)
        cout << 0 << endl;
    else
        cout << (count_zero_groups - 1) * min(a, b) + b << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}