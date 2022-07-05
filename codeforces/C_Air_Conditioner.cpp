#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> arr) {
    sort(arr.begin(), arr.end());
}

pair<int, int> merge_intevals(pair<int, int> p1, pair<int, int> p2) {
    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;

    int low = m, high = m;
    int t = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int dt;
        cin >> dt;
        // time elapsed since previous customer.
        dt -= t;

        int low_c, high_c;
        cin >> low_c >> high_c;

        pair<int, int> merged_interval = merge_intevals({low_c, high_c}, {low - dt, high + dt});
        if (merged_interval.first > merged_interval.second) {
            flag = false;
        } else {
            low = merged_interval.first;
            high = merged_interval.second;
            t += dt;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
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