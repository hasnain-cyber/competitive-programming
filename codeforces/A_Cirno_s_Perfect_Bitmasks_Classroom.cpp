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
        ll n;
        cin >> n;

        if (n == 1)
            cout << 3 << endl;
        else {
            ll k = 0;
            while(((1 << k) & n) == 0) k++; 

            ll ans = (1 << k);
            if ((ans ^ n) > 0)
                cout << ans << endl;
            else
                cout << ans + 1 << endl;
        }
    }
}