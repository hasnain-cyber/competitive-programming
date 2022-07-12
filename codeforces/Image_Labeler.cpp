#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        int s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
        }
        double ans = 0;
        if (n == m) {
            ans = s;
        } else if (n == m + 1) {
            ans = s - arr[0] - arr[1] + (arr[0] + arr[1]) / 2.0;
        } else {
            for (int i = n - m + 1; i < n; i++) {
                ans += arr[i];
            }

            if ((n - m + 1) & 1) {
                ans += arr[(n - m + 1) / 2];
            } else {
                ans += (arr[(n - m + 1) / 2] + arr[(n - m + 1) / 2 - 1]) / 2.0;
            }
        }

        cout << "Case #" << k << ": " << fixed << setprecision(2) << (ans) << endl;
    }
}