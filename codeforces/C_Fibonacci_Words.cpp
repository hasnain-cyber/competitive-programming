#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        bool flag = true;
        for (int i = 2; i < n && flag; i++) {
            int value1 = s[i] - 'A';
            int value2 = ((s[i - 1] - 'A') + (s[i - 2] - 'A')) % 26;

            if (value1 != value2) flag = false;
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}