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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<pair<string, int>> v;
        for (int i = 0; i < n; i++) {
            string current = "";
            for (int j = 0; j < n; j++) current.push_back(s[(j + i) % n]);

            if (i % 2 != n % 2) reverse(current.end() - i, current.end());

            v.push_back({current, i + 1});
        }

        sort(v.begin(), v.end());
        cout << v[0].first << endl;
        cout << v[0].second << endl;
    }
}