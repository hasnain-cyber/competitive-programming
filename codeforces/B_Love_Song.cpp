#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    ll prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (ll i = 1; i < n + 1; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + (int)(s[i - 1] - 'a') + 1;
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
    }
}

// correct