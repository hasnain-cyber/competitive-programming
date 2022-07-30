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
    int n, x;
    cin >> n >> x;

    if (n == 2)
    {
        if (x == 3)
        {
            cout << "1 1 2" << endl;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    // if there is a bit in x that is not set in any number until n;
    for (int i = 0; i <= 31; i++)
    {
        if ((x >> i))
        {
            bool flag = false;
            for (int j = 1; j <= n; j++)
            {
                if ((j >> i) == 1)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    // if n is power of 2, then that bit is set in only one number and cannot be removed,
    // so x must also have that bit set.
    if ((n & (n - 1)) == 0)
    {
        int k = log(n);
        if (!((x >> k) & 1))
        {
            cout << -1 << endl;
            return;
        }
    }

    vector<int> powers_of_two, not_power_of_two;
    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            powers_of_two.push_back(i);
        }
        else
        {
            not_power_of_two.push_back(i);
        }
    }

    // or all non powers of two.
    int curr = not_power_of_two[0];
    for (int i = 1; i < not_power_of_two.size(); i++)
    {
        curr = (curr | not_power_of_two[i]);
        cout << "1 " << curr << " " << not_power_of_two[i] << endl;
    }

    // now use remaining powers of two accordingly to manipulate the bits, since all the bits are set for now.
    for (int i = 0; i < powers_of_two.size(); i++)
    {
        int value = powers_of_two[i];
        int k = log2(value);
        if ((x >> k) & 1)
        {
            cout << "1 " << curr << " " << powers_of_two[i] << endl;
        }
        else
        {
            cout << "2 " << curr << " " << powers_of_two[i] << endl;
            curr ^= powers_of_two[i];
        }
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