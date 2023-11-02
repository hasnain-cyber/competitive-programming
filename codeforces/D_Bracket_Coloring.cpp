#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

vector<pair<bool, int>> condense(vector<pair<bool, int>>& arr) {
    vector<pair<bool, int>> ans;
    for (auto b : arr) {
        if (ans.empty() || ans.back().first != b.first) ans.push_back(b);
        else ans.back().second += b.second;
    }
    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int counter1 = 0;
    for (char ch : s) {
        counter1 += (ch == '(');
    }
    if (counter1 != n - counter1) {
        cout << -1 << endl;
        return;
    }

    vector<pair<bool, int>> temp;
    bool is_reversed = false;
    int counter = 0;
    counter1 = 0;
    for (int i = 0; i < n; i++) {
        if (counter == 0) {
            is_reversed = (s[i] == ')');
        }

        if (s[i] == '(') counter++;
        else counter--;

        counter1++;
        if (counter == 0) {
            temp.push_back({ is_reversed, counter1 });
            counter1 = 0;
        }
    }

    temp = condense(temp);
    int color_type = 1;
    vector<int> ans;
    for (auto p : temp) {
        for (int i = 0; i < p.second; i++) {
            ans.push_back(color_type);
        }
        if (color_type == 1) color_type = 2;
        else color_type = 1;
    }

    cout << (temp.size() == 1 ? 1 : 2) << endl;
    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}