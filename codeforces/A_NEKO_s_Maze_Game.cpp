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
        int n, q;
        cin >> n >> q;

        vector<vector<int>> path(2, vector<int>(n, 0));
        int blocked_pairs = 0;
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;

            int delta = (path[x][y] == 0 ? 1 : -1);
            path[x][y] = 1 - path[x][y];
            for (int dy = -1; dy <= 1; dy++) {
                if (y + dy < 0 || y + dy >= n) continue;

                if (path[1 - x][y + dy] == 1) blocked_pairs += delta;
            }

            if (blocked_pairs == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}