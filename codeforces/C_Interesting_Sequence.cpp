#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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

int range_and(int a, int b)
{
    int ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        int bit1 = ((a >> i) & 1);
        int bit2 = ((b >> i) & 1);

        if (bit1 == bit2)
        {
            ans |= (bit1 << i);
        }
        else
            break;
    }

    return ans;
}

void solve_testcase()
{
    int n, x;
    cin >> n >> x;

    int low = n, high = 5 * 1e18, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int value = range_and(n, mid);
        if (value > x)
        {
            low = mid + 1;
        }
        else if (value < x)
        {
            high = mid - 1;
        }
        else
        {
            high = mid - 1;
            ans = mid;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve_testcase();
    }
}