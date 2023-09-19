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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> pre(n);
    pre[0] = arr[0] - k;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + (arr[i] - k);
    }

    // use only good keys until i, then only bad keys
    int ans = -infinity;
    for (int i = -1; i < n; i++)
    {
        int temp_ans = (i == -1 ? 0 : pre[i]);
        for (int j = i + 1; j < min(n, i + 30); j++)
        {
            temp_ans += (arr[j] / (1 << (j - i)));
        }
        ans = max(ans, temp_ans);
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