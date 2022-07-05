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
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int l = 0, h = n;
    while (l <= h) {
        int mid = (l + h) / 2;

        vector<int> current_arr(n);
        for (int i = 0; i < n; i++) current_arr[i] = (i + 1) * mid + arr[i];
        sort(current_arr.begin(), current_arr.end());

        int current_cost = 0;
        for (int i = 0; i < mid; i++) {
            current_cost += current_arr[i];
        }

        if (current_cost <= s) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    vector<int> current_arr(n);
    for (int i = 0; i < n; i++) current_arr[i] = (i + 1) * h + arr[i];
    sort(current_arr.begin(), current_arr.end());

    int current_cost = 0;
    for (int i = 0; i < h; i++) {
        current_cost += current_arr[i];
    }

    cout << h << " " << current_cost << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}