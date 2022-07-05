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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

    int last_occupied_point = MIN, counter = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].first - arr[i].second > last_occupied_point) {
            last_occupied_point = arr[i].first;
            counter++;
        } else {
            if (i == n - 1) {
                counter++;
            } else {
                if (arr[i].first + arr[i].second < arr[i + 1].first) {
                    last_occupied_point = arr[i].first + arr[i].second;
                    counter++;
                } else {
                    last_occupied_point = arr[i].first;
                }
            }
        }
    }

    cout << counter << endl;
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