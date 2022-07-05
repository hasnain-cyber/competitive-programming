#include <bits/stdc++.h>

#define MOD 1000000007
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

using namespace std;

int max_path_sum(vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();

    int dp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[0][0] = arr[0][0];
            else if (i == 0)
                dp[0][j] = arr[0][j] + dp[0][j - 1];
            else if (j == 0)
                dp[i][0] = arr[i][0] + dp[i - 1][0];
            else
                dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> arr[i][j];

        if ((n + m) % 2 == 1) {
            // find max path sum
            int a = max_path_sum(arr);

            // find min path sum
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) arr[i][j] = -arr[i][j];

            int b = max_path_sum(arr);
            b = -b;

            if (a >= 0 && b <= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else
            cout << "NO" << endl;
    }
}