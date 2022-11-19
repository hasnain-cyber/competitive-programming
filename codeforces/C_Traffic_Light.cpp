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
    char color;
    cin >> color;
    string s;
    cin >> s;

    if (color == 'g')
    {
        cout << 0 << endl;
        return;
    }

    string s2 = s + s;
    vector<int> green_indices;
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2[i] == 'g')
        {
            green_indices.push_back(i);
        }
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == color)
        {
            // find the value of next green index greater than i
            int value = *upper_bound(green_indices.begin(), green_indices.end(), i) - i;
            ans = max(ans, value);
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
    while (t--)
    {
        solve_testcase();
    }
}