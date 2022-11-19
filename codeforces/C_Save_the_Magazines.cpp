#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int solve(int ci, vector<int> arr, string &bool_str, int n)
{
    if (ci == n)
        return 0;

    if (bool_str[ci] == '1')
        return arr[ci] + solve(ci + 1, arr, bool_str, n);
    else
    {
        if (ci == n - 1)
            return 0;
        else
        {
            if (bool_str[ci + 1] == '1')
            {
                if (arr[ci + 1] < arr[ci]) {
                    bool_str[ci] = '1';
                    bool_str[ci + 1] = '0';
                    return arr[ci] + solve(ci + 1, arr, bool_str, n);
                } else {
                    int ans = solve(ci + 1, arr, bool_str, n);
                    
                }
            }
            else
                return 0;
        }
    }

    if (ci == n - 1)
    {
        if (bool_str[ci] == '1')
            return arr[ci];
        else
            return 0;
    }
    else
    {
        if (bool_str[ci] == '1')
            return arr[ci] + solve(ci + 1, arr, bool_str, n);
        else
            return solve(ci + 1, arr, bool_str, n);
    }
}

void solve_testcase()
{
    int n;
    cin >> n;
    string bool_str;
    cin >> bool_str;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(0, arr, bool_str, n) << endl;
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