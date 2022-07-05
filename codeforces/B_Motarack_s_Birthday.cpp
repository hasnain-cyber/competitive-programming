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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max_adjacent_value = MIN, min_adjacent_value = MAX, counter = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            counter++;
            if (i < n - 1 && arr[i + 1] != -1) {
                max_adjacent_value = max(max_adjacent_value, arr[i + 1]);
                min_adjacent_value = min(min_adjacent_value, arr[i + 1]);
            }
            if (i > 0 && arr[i - 1] != -1) {
                max_adjacent_value = max(max_adjacent_value, arr[i - 1]);
                min_adjacent_value = min(min_adjacent_value, arr[i - 1]);
            }
        }
    }

    int k = 1;
    if (counter > 0) {
        k = (max_adjacent_value + min_adjacent_value) / 2;
    }

    int max_difference = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == -1 && arr[i + 1] != -1) {
            max_difference = max(max_difference, abs(arr[i + 1] - k));
        } else if (arr[i] != -1 && arr[i + 1] == -1) {
            max_difference = max(max_difference, abs(arr[i] - k));
        } else {
            max_difference = max(max_difference, abs(arr[i] - arr[i + 1]));
        }
    }

    cout << max_difference << " " << k << endl;
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