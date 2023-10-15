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

vector<int> lis(vector<int>& arr, int n) {
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n;i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[low] = arr[i];
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

    int ans = 0;
    int mn = n + 1, mn_win = n + 1;
    for (int i = 0; i < n;i++) {
        // can go left, but can't go to a winning position
        if (arr[i] > mn && arr[i] < mn_win) {
            ans++;
            mn_win = arr[i];
        }
        mn = min(mn, arr[i]);
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