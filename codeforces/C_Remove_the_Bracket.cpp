#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr)
{
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase()
{
    int n, s;
    cin >> n >> s;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        if (i == 0 || i == n - 1)
        {
            x[i] = y[i] = value;
        }
        else if (value <= s)
        {
            x[i] = 0, y[i] = value;
        }
        else
        {
            x[i] = s, y[i] = value - s;
        }
    }

    vector<vector<int>> dp(n, vector<int>(2));
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + y[i - 1] * x[i], dp[i - 1][1] + x[i - 1] * x[i]);
        dp[i][1] = min(dp[i - 1][0] + y[i - 1] * y[i], dp[i - 1][1] + x[i - 1] * y[i]);
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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