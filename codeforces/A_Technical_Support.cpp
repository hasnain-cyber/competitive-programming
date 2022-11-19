#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    string s;
    cin >> s;

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Q')
            counter++;
        else
            counter--;
        counter = max(counter, (int)0);
    }

    if (counter > 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
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