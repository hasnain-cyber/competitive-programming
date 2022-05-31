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
        if (n & 1) {
            cout << -1 << endl;
        } else {
            ll minimum, maximum;
            bool flag = false;
            for (ll a = 0; a <= ceil(n / (ld)4); a++) {
                ld check_value = (n - 4 * a) / 6.0;
                if (check_value == ll(check_value)) {
                    minimum = a + check_value;
                    flag = true;
                    break;
                }
            }

            for (ll b = 0; b <= ceil(n / (ld)6); b++) {
                ld check_value = (n - 6 * b) / (ld)4;
                if (check_value == ll(check_value)) {
                    maximum = b + check_value;
                    break;
                }
            }

            if (flag)
                cout << minimum << " " << maximum << endl;
            else
                cout << -1 << endl;
        }
    }
}