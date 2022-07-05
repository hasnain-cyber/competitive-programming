#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());

        int ans = 0;
        int i = 0;
        while (i < n) {
            bool flag = false;
            for (int j = i; j < n; j++) {
                int value = arr[j] * (j - i + 1);
                if (value >= x) {
                    flag = true;
                    i = j + 1;
                    break;
                }
            }

            if (flag)
                ans++;
            else
                break;
        }

        cout << ans << endl;
    }
}