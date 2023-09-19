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

bool check(vector<int> arr, int n, int value)
{
    vector<int> support(n, 0);
    for (int i = n - 1; i >= 2; i--)
    {
        if (arr[i] + support[i] < value)
            return false;
        int lend = min(arr[i] + support[i] - value, arr[i]);
        support[i - 1] += lend / 3;
        support[i - 2] += 2 * (lend / 3);
    }

    return arr[0] + support[0] >= value && arr[1] + support[1] >= value;
}

void solve_testcase()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min_value = arr[0], max_value = arr[0];
    for (int i = 1; i < n; i++)
    {
        min_value = min(min_value, arr[i]);
        max_value = max(max_value, arr[i]);
    }

    int low = min_value, high = max_value, ans = min_value;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (check(arr, n, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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