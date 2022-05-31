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
        string s;
        cin >> s;
        ll n = s.size();

        ll last_one = -1, first_zero = -1;
        for (ll i = 0; i < n; i++)
            if (s[i] == '1') last_one = i;
        for (ll i = n - 1; i >= 0; i--)
            if (s[i] == '0') first_zero = i;

        ll ans;
        if (last_one != -1 && first_zero != -1)
            ans = first_zero - last_one + 1;
        else if (last_one != -1)
            ans = n - last_one;
        else if (first_zero != -1)
            ans = first_zero + 1;
        else
            ans = n;

        cout << ans << endl;
    }
}

// correct