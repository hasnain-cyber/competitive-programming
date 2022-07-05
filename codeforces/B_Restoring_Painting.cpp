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

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int max_pair = max(a + b, max(a + c, max(b + d, c + d)));
    int min_pair = min(a + b, min(a + c, min(b + d, c + d)));

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        int s_min = 1 + k + max_pair;      // min sum required to keep k_min_positive.
        int k_max = s_min - min_pair - k;  // due to this a k_max will occur, and it's range will tell us how much farther we are from n.

        ans += max(n - k_max + 1, (int)0);
    }

    cout << ans << endl;
}