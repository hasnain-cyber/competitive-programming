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
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), send_arr(m);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < m; i++) cin >> send_arr[i];

        map<int, int> mp;
        for (int i = 0; i < n; i++) mp[arr[i]] = i;

        int last_visited = -1;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int index = mp[send_arr[i]];
            if (index < last_visited)
                ans++;
            else {
                last_visited = index;
                ans += (2 * (index - i) + 1);
            }
        }

        cout << ans << endl;
    }
}