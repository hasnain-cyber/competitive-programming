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
        int n;
        cin >> n;

        int ans = 0;
        while (n > 0) {
            int k = log2(n);
            ans += pow(2, k + 1) - 1;
            n -= pow(2, k);
        }

        cout << ans << endl;
    }
}