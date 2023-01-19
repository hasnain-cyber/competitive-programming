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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> freq;
    int curr_sum = 0, ans = 0, max_freq = 0;
    bool zero_detected = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (zero_detected) {
                ans += max_freq;
            } else {
                ans += freq[0];
            }

            zero_detected = true;
            max_freq = 0;
            curr_sum = 0;
            freq.clear();
        }

        curr_sum += arr[i];
        max_freq = max(max_freq, ++freq[curr_sum]);
    }
    if (zero_detected)
        ans += max_freq;
    else
        ans += freq[0];

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}