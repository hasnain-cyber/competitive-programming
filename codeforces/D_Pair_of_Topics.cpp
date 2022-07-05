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
    t = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = a[i] - b[i];

        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int bigger_index = upper_bound(arr.begin() + i + 1, arr.end(), -arr[i]) - arr.begin();
            ans += (n - bigger_index);
        }

        cout << ans << endl;
    }
}