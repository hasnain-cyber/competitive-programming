#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll fast_power(ll a, ll b, ll m) {
    if (b == 0) {
        return 1;
    } else {
        if (b & 1) {
            return ((a % m) * (fast_power(a, b - 1, m) % m)) % m;
        } else {
            return fast_power(((a % m) * (a % m)) % m, b >> 1, m);
        }
    }
}

int main() {
    cout << fast_power(2, 100, MOD) << endl;
}