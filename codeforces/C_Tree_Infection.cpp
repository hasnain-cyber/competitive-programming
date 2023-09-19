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

void rec(vector<int> &arr, int &ans)
{
    if (arr.empty())
        return;

    int last = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[0])
            last = i;
        else
            break;
    }
    arr[last]--;

    for (int i = 0; i < arr.size(); i++)
        arr[i]--;

    while (!arr.empty() && arr.back() <= 0)
        arr.pop_back();

    ans++;
    rec(arr, ans);
}

void solve_testcase()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int parent;
        cin >> parent;

        arr[parent - 1]++;
    }
    arr.push_back(1);
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    while (!arr.empty() && arr.back() == 0)
        arr.pop_back();

    // ans also represents curr time
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] -= (arr.size() - i);
        ans++;
    }

    while (!arr.empty() && arr.back() <= 0)
        arr.pop_back();

    rec(arr, ans);

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