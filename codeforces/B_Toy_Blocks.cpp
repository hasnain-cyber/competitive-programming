#include <bits/stdc++.h>

#define MOD 1000000007
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }

        int l = 0, r = pow(10, 14);
        // we try to find new value m, that is sum / (n - 1)
        int k;
        while (l <= r) {
            int mid = (l + r) / 2;

            // m is less than already existing value of sum / (n - 1), then discard it.
            if (mid * (n - 1) < s) {
                l = mid + 1;
                continue;
            }

            // if any value in array is already greater than m, then discard it.
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (arr[i] > mid) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                l = mid + 1;
                continue;
            } else {
                k = mid;
                r = mid - 1;
                continue;
            }
        }

        cout << k * (n - 1) - s << endl;
    }
}