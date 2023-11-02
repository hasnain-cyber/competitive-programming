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

vector<pair<int, int>> condense(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty()) {
            if (arr[i] == 0) ans.push_back({ 0, 1 });
            else ans.push_back({ 1, arr[i] });
        }
        else if (arr[i] == 0) {
            if (ans.back().first == 0) ans.back().second++;
            else ans.push_back({ 0, 1 });
        }
        else {
            if (ans.back().first == 0) ans.push_back({ 1, arr[i] });
            else ans.back().second = max(ans.back().second, arr[i]);
        }
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto condensed_arr = condense(arr);
    bool prev_available = false;
    int ans = 0;
    n = condensed_arr.size();
    for (int i = 0; i < n; i++) {
        auto ele = condensed_arr[i];
        if (ele.first != 0) {
            ans++;
            if (i == 0) {
                prev_available = true;
            }
            else {
                ans += max(condensed_arr[i - 1].second - 1 - prev_available, (int)0);
                prev_available = ele.second > 1 || (prev_available && condensed_arr[i - 1].second == 1);
            }
        }
    }
    if (condensed_arr[n - 1].first == 0) {
        ans += (condensed_arr[n - 1].second - prev_available);
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}