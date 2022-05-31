#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll a, b;
    cin >> a >> b;

    ll k = log2(b) + 1;
    ll ans = (a << k) + b;

    cout << ans % MOD << endl;
}

// correct