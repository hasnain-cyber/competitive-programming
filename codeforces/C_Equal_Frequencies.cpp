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

int compare(string &a, string &b)
{
    int n = a.size();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            ans++;
    }
    return ans;
}

void solve_testcase()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s)
        freq[c]++;

    vector<pair<int, char>> freq_count;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (freq.count(c))
        {
            freq_count.push_back({freq[c], c});
        }
        else
        {
            freq_count.push_back({0, c});
        }
    }
    sort(freq_count.begin(), freq_count.end());
    reverse(freq_count.begin(), freq_count.end());

    int ans = n;
    string ans_string = "";
    for (int k = 1; k <= min(n, (int)26); k++)
    {
        if (n % k != 0)
            continue;

        vector<char> temp_str(n, '/');
        int required_freq = n / k;
        map<char, int> remaining_chars;
        for (int i = 0; i < k; i++)
        {
            remaining_chars[freq_count[i].second] = required_freq;
        }

        // initial pass to fill the already existing characters
        map<char, int> curr_freq;
        for (int i = 0; i < n; i++)
        {
            if (remaining_chars.count(s[i]) && curr_freq[s[i]] < required_freq)
            {
                curr_freq[s[i]]++;
                remaining_chars[s[i]]--;
                if (remaining_chars[s[i]] == 0)
                {
                    remaining_chars.erase(s[i]);
                }
                temp_str[i] = s[i];
            }
        }

        // fill the remaining characters in the remaining spaces
        for (int i = 0; i < n; i++)
        {
            if (temp_str[i] == '/')
            {
                char c = remaining_chars.begin()->first;
                temp_str[i] = c;
                remaining_chars[c]--;
                if (remaining_chars[c] == 0)
                {
                    remaining_chars.erase(c);
                }
            }
        }

        string temp_str_string = "";
        for (char c : temp_str)
        {
            temp_str_string += c;
        }
        int temp_ans = compare(s, temp_str_string);
        if (temp_ans < ans)
        {
            ans = temp_ans;
            ans_string = temp_str_string;
        }
    }

    cout << ans << endl;
    cout << ans_string << endl;
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