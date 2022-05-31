#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool is_prime(ll n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    } else {
        for (ll i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    ll n;
    cin >> n;

    // reverse the number.
    ll rev = 0;
    ll temp = n;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }

    if (is_prime(n) && is_prime(rev)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// correct