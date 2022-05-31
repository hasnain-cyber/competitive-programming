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
        string s;
        cin >> s;

        ll counter = 1;
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                counter++;
            } else {
                if (counter & 1) {
                    ans++;
                    counter = 2;
                } else {
                    counter = 1;
                }
            }
        }

        if (counter & 1) {
            ans++;
        }

        cout << ans << endl;
    }
}

// correct