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
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "NO" << endl;
        return;
    }

    int count1 = 0, count2 = 0;
    for (char c : s1) {
        if (c == '1') count1++;
    }
    for (char c : s2) {
        if (c == '1') count2++;
    }

    if ((count1 == 0 && count2 > 0) || (count1 > 0 && count2 == 0)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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