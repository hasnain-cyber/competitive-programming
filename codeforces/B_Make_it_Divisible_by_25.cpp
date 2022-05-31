#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll solve(ll n, ll current_steps) {
    if (n % 25 == 0) {
        return current_steps;
    } else if (n < 25) {
        return MAX;
    } else {
        string n_string = to_string(n);
        ll ans = MAX;

        for (int i = 0; i < n_string.size(); i++) {
            string new_number = n_string.substr(0, i) + n_string.substr(i + 1);
            ll new_number_int = stoll(new_number);

            if (new_number_int % 25 == 0) {
                ans = min(ans, current_steps + 1);
            } else {
                ans = min(ans, solve(new_number_int, current_steps + 1));
            }
        }

        return ans;
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        cout << solve(n, 0) << endl;
    }
}

// tle