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

void print_arr(vector<T> &arr) {
    for (T element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int check_s(string s) {
    int counter = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            counter++;
        } else {
            if (counter == 0) {
                return false;
            } else {
                counter--;
            }
        }
    }

    return counter == 0;
}

void solve_testcase() {
    string s;
    cin >> s;

    vector<vector<char>> replace_values = {
        {'(', '(', ')'},
        {'(', ')', ')'},
        {')', ')', '('},
        {')', '(', '('},
        {'(', ')', '('},
        {')', '(', ')'},
    };

    for (vector<char> replace_value : replace_values) {
        string new_string;
        for (char ch : s) {
            if (ch == 'A') {
                new_string.push_back(replace_value[0]);
            } else if (ch == 'B') {
                new_string.push_back(replace_value[1]);
            } else {
                new_string.push_back(replace_value[2]);
            }
        }

        if (check_s(new_string)) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}