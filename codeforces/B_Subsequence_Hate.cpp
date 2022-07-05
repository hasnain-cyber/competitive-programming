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

        int count_zeros = 0, count_ones = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                count_zeros++;
            else
                count_ones++;
        }

        int zeros_until_now = 0, ones_until_now = 0;
        int ans = MAX;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                zeros_until_now++;
            else
                ones_until_now++;

            int cost1 = ones_until_now + (count_zeros - zeros_until_now);
            int cost2 = zeros_until_now + (count_ones - ones_until_now);
            ans = min(ans, min(cost1, cost2));
        }

        cout << ans << endl;
    }
}