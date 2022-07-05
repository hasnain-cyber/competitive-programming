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

    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            left[i] = 1;
        else {
            if (arr[i] > arr[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1)
            right[i] = 1;
        else {
            if (arr[i] < arr[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        }
    }

    int ans = *max_element(left.begin(), left.end());
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans = max(ans, right[i + 1]);
        } else if (i == n - 1) {
            ans = max(ans, left[i - 1]);
        } else {
            if (arr[i - 1] < arr[i + 1]) {
                ans = max(ans, left[i - 1] + right[i + 1]);
            }
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