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

    int min_value_index = min_element(arr.begin(), arr.end()) - arr.begin();
    int max_value_index = max_element(arr.begin(), arr.end()) - arr.begin();
    int min_value_element = arr[min_value_index];
    int max_value_element = arr[max_value_index];

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += abs(arr[i] - arr[i + 1]);
    }

    if (min_value_element > 1)
    {
        ans += min({arr[0] - 1,
                    arr[n - 1] - 1,
                    2 * (min_value_element - 1)});
    }

    if (k > max_value_element)
    {
        ans += min({k - arr[0],
                    k - arr[n - 1],
                    2 * (k - max_value_element)});
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