#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

vector<bool> seive(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    return is_prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    vector<bool> primes = seive(pow(10, 6));
    while (t--) {
        ll n, e;
        cin >> n >> e;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll element = arr[i];
            if (primes[arr[i]]) {
                // forward
                ll forward_length = 0;
                for (ll j = i + e; j < n; j += e) {
                    if (arr[j] == 1)
                        forward_length++;
                    else
                        break;
                }

                // backward
                ll backward_length = 0;
                for (ll j = i - e; j >= 0; j -= e) {
                    if (arr[j] == 1)
                        backward_length++;
                    else
                        break;
                }

                ans += ((forward_length + 1) * (backward_length + 1) - 1);
            }
        }

        cout << ans << endl;
    }
}