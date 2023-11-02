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
        if (ans.empty() || ans.back().first != arr[i]) {
            ans.push_back({ arr[i], 1 });
        }
        else {
            ans.back().second++;
        }
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    auto condensed_arr = condense(arr);
    if (condensed_arr.size() == 1) {
        cout << condensed_arr[0].second / 2 << endl;
        return;
    }

    int ans = 0;
    int left = 0;
    for (auto ele : condensed_arr) {
        left += ele.second;
        ans = max(ans, left * (n - left));
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}