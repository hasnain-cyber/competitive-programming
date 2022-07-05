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
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        bool will_flip = false;
        for (ll i = 0; i < n; i++) {
            if (arr[i] & 1) will_flip = !will_flip;
        }

        bool should_flip = (x & 1) != (y & 1);
        if (will_flip && should_flip)
            cout << "Alice" << endl;
        else if (!will_flip && !should_flip)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
}