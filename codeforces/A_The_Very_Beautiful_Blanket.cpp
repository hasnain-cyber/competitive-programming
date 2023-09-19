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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        ans[i][0] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            ans[i][j] = ans[i][j - 1] + 256;
        }
    }

    cout << n * m << endl;
    for (int i = 0; i < n; i++)
    {
        print_arr(ans[i]);
    }
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