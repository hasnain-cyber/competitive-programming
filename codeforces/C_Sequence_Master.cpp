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
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];

    int ans = infinity;
    if (n == 1)
    {
        ans = abs(arr[0] - arr[1]);
    }
    else if (n == 2)
    {
        int temp_ans = 0;
        for (int i = 0; i < 2 * n; i++)
            temp_ans += abs(arr[i] - 2);
        ans = min(ans, temp_ans);
    }

    int temp_ans = 0;
    for (int i = 0; i < 2 * n; i++)
        temp_ans += abs(arr[i]);
    ans = min(ans, temp_ans);

    if (n % 2 == 0)
    {
        int s = 0;
        for (int i = 0; i < 2 * n; i++)
            s += abs(arr[i] + 1);

        int temp_ans = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            temp_ans = s - abs(arr[i] + 1) + abs(arr[i] - n);
            ans = min(ans, temp_ans);
        }
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