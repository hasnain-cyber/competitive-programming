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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    int counter = 0;
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            counter++;
        }
    }

    if (counter == 1)
    {
        if (mp[*max_element(arr.begin(), arr.end())] == 1)
        {
            int max_freq = -infinity;
            for (auto it : mp)
            {
                if (it.second > 1)
                {
                    max_freq = max(max_freq, it.second);
                }
            }

            if (max_freq > 2)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 2 << endl;
            }
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else
    {
        cout << ceil(counter / 2.0) << endl;
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