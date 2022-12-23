#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    // total positions
    int N = pow(10, 7);

    // n beacons
    int n;
    cin >> n;
    vector<int> beacons(N, 0);
    for (int i = 0; i < n; i++) {
        int position, power;
        cin >> position >> power;
        beacons[position] = power;
    }

    // dp represents saved beacons to the left of the current position i
    vector<int> dp(N, 0);
    if (beacons[0] != 0) {
        dp[0] = 1;
    }
    for (int i = 1; i < N; i++) {
        // if there is no beacon at position i
        if (beacons[i] == 0) {
            dp[i] = dp[i - 1];
        } else {
            if (i - beacons[i] >= 1) {
                dp[i] = dp[i - beacons[i] - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
    }
    
    // now just evaluate the maximum number of saved beacons
    int max_saved = 0;
    for (int i = 0; i < N; i++) {
        max_saved = max(max_saved, dp[i]);
    }

    cout << n - max_saved << endl;
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