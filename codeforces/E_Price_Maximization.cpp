#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define loop(n) for (int i = 0; i < n; i++)
#define vi vector<int>

#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    loop(t) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        loop(n) cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] / k;
            a[i] %= k;
        }

        sort(a.begin(), a.end());
        int l = 0, h = n - 1;
        while (l < h) {
            int check_value = a[l] + a[h];
            if (check_value < k)
                l++;
            else
                l++, h--, ans++;
        }

        cout << ans << endl;
    }
}