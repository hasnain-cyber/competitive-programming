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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(k);
    for (int i = 0; i < k; i++) cin >> arr[i].first;   // position
    for (int i = 0; i < k; i++) cin >> arr[i].second;  // temperature

    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[arr[i].first] = arr[i].second;
    }

    vector<int> left_arr(n + 1);
    int current_left = INT_MAX;  // taken INT_MAX so that it does not overflow.
    for (int i = 1; i <= n; i++) {
        if (mp.count(i)) {
            current_left = min(current_left + 1, mp[i]);
        } else {
            current_left++;
        }

        left_arr[i] = current_left;
    }

    vector<int> right_arr(n + 1);
    int current_right = INT_MAX;
    for (int i = n; i >= 1; i--) {
        if (mp.count(i)) {
            current_right = min(current_right + 1, mp[i]);
        } else {
            current_right++;
        }

        right_arr[i] = current_right;
    }

    for (int i = 1; i <= n; i++) cout << min(left_arr[i], right_arr[i]) << " ";
    cout << endl;
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