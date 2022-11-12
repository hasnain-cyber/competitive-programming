#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
const int N = 1e2 + 5, mx = 1e5;
int test_case = 1, n, dp[N], tally;
string t;
vector<string> a;

int solve(int index) {
    if (index == tally)
        return dp[index] = 0;
    if (dp[index] != mx)
        return dp[index];

    int operations = mx;

    for (int i = 0; i < n; i++)
        if (index + a[i].length() - 1 < tally && t.substr(index, a[i].length()) == a[i])
            for (int t = 1; t <= a[i].length(); t++) {
                operations = min(operations, 1 + solve(index + t));
            }

    return dp[index] = operations;
}

int32_t main() 
{
    cin >> test_case;
    while (test_case--) {
        fill(dp, dp + N, mx);
        cin >> t >> n;
        tally = t.length();

        a.resize(n);
        for (string &s : a)
            cin >> s;

        int res = solve(0);
        if (res == mx)
            cout << -1 << endl;
        else {
            cout << res << endl;
            vector<pair<int, int>> paths;
            int current_operations = res;
            int index = 0;
            while (index < tally) {
                for (int i = 0; i < n; i++) 
                {
                    bool changed = false;
                    if (index + a[i].length() - 1 < tally && t.substr(index, a[i].length()) == a[i])
                        for (int k = 1; k <= a[i].length(); k++) 
                        {
                            if (dp[index] == 1 + dp[index + k]) 
                            {
                                changed = true;
                                index = index + k;
                                paths.push_back({i, index - k});
                            }
                            if (changed)
                                break;
                        }

                    if (changed)
                        break;
                }
            }
            for (pair<int, int> x : paths)
                {
                cout << x.first + 1 << ' ' << x.second + 1 << '\n';
                }
        }
    }
    return 0;
}
