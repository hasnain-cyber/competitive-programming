#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll updated = 1, ans = 0;
        while (updated < n) {
            if (updated <= k) {
                updated *= 2;
                ans++;
            } else {
                ans += ceil((n - updated) / double(k));
                break;
            }
        }

        cout << ans << endl;
    }
}

// correct