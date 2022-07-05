#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
}

void solve_testcase() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), compare);

    int i = 0, j = 0;
    int current_sum = 0, ans = MIN;
    while (j < n) {
        if (i == j) {
            current_sum += arr[i].second;
            j++;
        } else {
            while (arr[j].first - arr[i].first >= d) {
                current_sum -= arr[i].second;
                i++;
            }
            current_sum += arr[j].second;
            j++;
        }

        ans = max(ans, current_sum);
    }

    cout << ans << endl;
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