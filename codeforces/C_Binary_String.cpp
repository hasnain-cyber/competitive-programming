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
    string s;
    cin >> s;
    int n = s.size();

    int counter_zero = 0;
    for (char ch : s)
    {
        if (ch == '0')
            counter_zero++;
    }
    int counter_one = n - counter_zero;

    vector<int> prefix_sum(n);
    prefix_sum[0] = (s[0] == '0' ? -1 : 1);
    for (int i = 0; i < n; i++)
    {
        curr += (s[i] == '0' ? -1 : 1);
        min_value = min(min_value, curr);
        max_value = max(max_value, curr);
    }

    cout << max_value << " " << min_value << endl;

    int low = 0, high = n, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (max_value - min_value >= counter_one - 2 * mid)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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