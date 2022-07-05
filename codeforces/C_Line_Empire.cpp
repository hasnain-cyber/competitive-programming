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
        int n, move_cost, conquer_cost;
        cin >> n >> move_cost >> conquer_cost;
        vector<int> a(n + 1);
        a.push_back(0);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int l = 0, r = 0;
        int ans = 0;
        while (r != n) {
            if (l == r) {
                ans += conquer_cost * (a[r + 1] - a[l]);
                r++;
            } else {
                int cost1 = conquer_cost * (a[r + 1] - a[l]);
                int cost2 = move_cost * (a[l + 1] - a[l]) + conquer_cost * (a[r + 1] - a[l + 1]);

                if (cost1 > cost2) {
                    ans += move_cost * (a[l + 1] - a[l]);
                    l++;
                } else {
                    ans += cost1;
                    r++;
                }
            }
            // cout << ans << endl;
        }

        cout << ans << endl;
        // cout << "Done" << endl;
    }
}