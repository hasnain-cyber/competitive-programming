#include <bits/stdc++.h>

#define MOD 1000000007

#define int long long int

using namespace std;

map<int, int> fact_map;
int fact(int n, int mod)
{
    if (n == 0)
        return 1;

    if (fact_map.find(n) != fact_map.end())
        return fact_map[n];

    int ans = (n * fact(n - 1, mod)) % mod;
    fact_map[n] = ans;
    return ans;
}

void solve_testcase()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<bool>> grid(n, vector<bool>(m, false));
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a - 1][b - 1] = true;
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1 && grid[i][j])
            {
                // color all reachable squares in the color of (i, j)
                queue<pair<int, int>> q;
                q.push({i, j});
                dp[i][j] = counter;
                while (!q.empty())
                {
                    int curr_i = q.front().first;
                    int curr_j = q.front().second;
                    q.pop();

                    // check all 8 directions as a horse in chess
                    int di[] = {-2, -2, -1, -1, 1, 1, 2, 2};
                    int dj[] = {-1, 1, -2, 2, -2, 2, -1, 1};
                    for (int k = 0; k < 8; k++)
                    {
                        int curr_i2 = curr_i + di[k];
                        int curr_j2 = curr_j + dj[k];
                        if (curr_i2 >= 0 && curr_i2 < n && curr_j2 >= 0 && curr_j2 < m && grid[curr_i2][curr_j2] && dp[curr_i2][curr_j2] == -1)
                        {
                            dp[curr_i2][curr_j2] = counter;
                            q.push({curr_i2, curr_j2});
                        }
                    }
                }
                counter++;
            }
        }
    }

    vector<int> freq(counter, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] != -1)
                freq[dp[i][j]]++;
        }
    }

    int ans = 1;
    for (int i = 0; i < counter; i++)
    {
        ans = (ans * fact(freq[i], MOD)) % MOD;
    }

    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve_testcase();
    }
}