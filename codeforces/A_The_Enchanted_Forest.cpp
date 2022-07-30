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

void solve_testcase()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    if (k <= n)
    {
        // find the largest array of length k;
        int current = 0;
        for (int i = 0; i < k; i++)
        {
            current += arr[i];
        }
        ans = max(ans, current);

        for (int i = 0; i + k < n; i++)
        {
            current -= arr[i];
            current += arr[i + k];

            ans = max(ans, current);
        }

        ans += (k * (k - 1)) / 2;
    }
    else
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += arr[i];
        }
        ans += s;

        ans += (n * k) - (n * (n + 1)) / 2;
    }

    cout << ans << endl;
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