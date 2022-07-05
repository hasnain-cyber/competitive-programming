#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll s = 0;
        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            s += temp;
        }

        cout << max((ll)0, s - m) << endl;
    }
}