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
    int n = 100;
    vector<bool> ans = seive(n);

    for (int i = 0; i <= n; i++) {
        if (ans[i]) {
            cout << i << " ";
        }
    }
}