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

void solve_testcase() {
    int n;
    cin >> n;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (ans.empty()) {
            ans.push_back({ value });
            continue;
        }

        vector<int> new_list = ans.back();
        if (value == 1) new_list.push_back(1);
        else {
            while (!new_list.empty() && new_list.back() != value - 1) new_list.pop_back();
            if (new_list.empty())  new_list.push_back(value);
            else new_list.back()++;
        }
        ans.push_back(new_list);
    }

    for (auto ele : ans) {
        string temp;
        for (int i = 0; i < ele.size(); i++) {
            temp.append(to_string(ele[i]));
            if (i != ele.size() - 1) {
                temp.push_back('.');
            }
        }
        cout << temp << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}