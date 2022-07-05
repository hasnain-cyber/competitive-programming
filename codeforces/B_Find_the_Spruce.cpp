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
        vector<vector<char>> arr(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> arr[i][j];

        vector<vector<int>> l(n, vector<int>(m, 0));
        vector<vector<int>> r(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = 0; j < m; j++) {
                l[i][j] = counter;
                if (arr[i][j] == '.')
                    counter = 0;
                else
                    counter++;
            }

            counter = 0;
            for (int j = m - 1; j >= 0; j--) {
                r[i][j] = counter;
                if (arr[i][j] == '.')
                    counter = 0;
                else
                    counter++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == '.') continue;

                for (int height = 0; i + height < n; height++) {
                    if (l[i + height][j] < height || r[i + height][j] < height || arr[i + height][j] == '.')
                        break;
                    else
                        ans++;
                }
            }
        }

        cout << ans << endl;
    }
}