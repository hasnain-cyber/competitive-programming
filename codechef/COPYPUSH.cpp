#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr)
{
    for (T element : arr)
    {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr)
{
    sort(arr.begin(), arr.end());
}

bool check(string &s, int i, int j)
{
    if (i == j)
    {
        return true;
    }

    int length = j - i + 1;
    if (length % 2 == 1)
    {
        j--;
        length--;
    }

    for (int index = i; index + length / 2 <= j; index++)
    {
        if (s[index] != s[index + length / 2])
        {
            return false;
        }
    }

    return check(s, i, length / 2 - 1);
}

void solve_testcase()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (check(s, 0, n - 1))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve_testcase();
    }
}