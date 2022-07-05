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
    string s;
    cin >> s;
    int n = s.size();

    int count_ones = 0, count_twos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            count_ones++;
        else if (s[i] == '2')
            count_twos++;
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        int element = s[i];
        if (s[i] == '0')
            ans.push_back(s[i]);
        else if (s[i] == '1')
            continue;
        else {
            for (int i = 0; i < count_ones; i++) ans.push_back('1');
            for (int j = i; j < n; j++) {
                if (s[j] != '1') ans.push_back(s[j]);
            }
            break;
        }
    }

    if (count_twos == 0) {
        for (int i = 0; i < count_ones; i++) ans.push_back('1');
    }

    cout << ans << endl;
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