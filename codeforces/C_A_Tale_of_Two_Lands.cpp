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

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort_arr(arr);

    int count_zeros = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0) count_zeros++;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int length;
        if (arr[i] > 0) {
            int upper_index = upper_bound(arr.begin(), arr.end(), 2 * arr[i]) - arr.begin();
            upper_index--;
            int lower_index = lower_bound(arr.begin(), arr.end(), arr[i] + 1) - arr.begin();

            length = (upper_index - lower_index + 1);
        } else if (arr[i] < 0) {
            int upper_index = upper_bound(arr.begin(), arr.end(), arr[i] - 1) - arr.begin();
            upper_index--;
            int lower_index = lower_bound(arr.begin(), arr.end(), -2 * arr[i]) - arr.begin();

            length = (upper_index - lower_index + 1);
        } else {
            length = count_zeros;
        }

        if (length > 0) {
            ans += length;
        }
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