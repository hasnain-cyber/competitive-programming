#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    int ans_index = -1;
    int max_second = arr[0].first.second;
    for (int i = 1; i < n && ans_index == -1; i++) {
        if (max_second < arr[i].first.first) {
            ans_index = i;
        }
        max_second = max(max_second, arr[i].first.second);
    }

    if (ans_index == -1) {
        cout << -1 << endl;
    } else {
        vector<int> ans_arr(n);
        for (int i = 0; i < n; i++) {
            if (i < ans_index) {
                ans_arr[arr[i].second] = 1;
            } else {
                ans_arr[arr[i].second] = 2;
            }
        }
        for (int i = 0; i < n; i++) cout << ans_arr[i] << " ";
        cout << endl;
    }
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