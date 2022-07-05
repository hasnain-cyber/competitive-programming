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
        int n, z;
        cin >> n >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = MIN;
        for (int i = 0; i < n; i++) ans = max(ans, arr[i] | z);

        cout << ans << endl;
    }
}