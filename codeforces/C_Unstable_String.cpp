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
        string s;
        cin >> s;
        int n = s.size();

        int ans = 0;
        vector<int> zero_position = {-1, -1};
        vector<int> one_position = {-1, -1};
        for (int i = 0; i < n; i++) {
            int current;
            if (s[i] == '0') {
                current = max(zero_position[(i + 1) % 2], one_position[i % 2]);
                zero_position[i % 2] = i;
            } else if (s[i] == '1') {
                current = max(one_position[(i + 1) % 2], zero_position[i % 2]);
                one_position[i % 2] = i;
            } else {
                int current1 = max(zero_position[(i + 1) % 2], one_position[i % 2]);
                int current2 = max(one_position[(i + 1) % 2], zero_position[i % 2]);
                current = min(current1, current2);
            }

            ans += (i - current);
        }

        cout << ans << endl;
    }
}