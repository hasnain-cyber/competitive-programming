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
    int r, c;
    cin >> r >> c;
    string s;
    cin >> s;
    int n = s.size();

    int curr_x = 0, curr_y = 0;
    vector<vector<int>> pre(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            curr_x--;
        else if (s[i] == 'R')
            curr_x++;
        else if (s[i] == 'D')
            curr_y++;
        else
            curr_y--;

        pre[i][0] = min(i > 0 ? pre[i - 1][0] : curr_x, curr_x);
        pre[i][1] = max(i > 0 ? pre[i - 1][1] : curr_x, curr_x);
        pre[i][2] = min(i > 0 ? pre[i - 1][2] : curr_y, curr_y);
        pre[i][3] = max(i > 0 ? pre[i - 1][3] : curr_y, curr_y);
    }

    int h = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = max(-pre[i][0], (int)0);
        if (pos < c && pos + pre[i][1] < c)
        {
            h = pos;
        }
        else
        {
            break;
        }
    }

    int v = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = max(-pre[i][2], (int)0);
        if (pos < r && pos + pre[i][3] < r)
        {
            v = pos;
        }
        else
        {
            break;
        }
    }

    cout << v + 1 << " " << h + 1 << endl;
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