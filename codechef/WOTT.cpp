#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll set_bits = 0, unset_bits = 0;
    while (n > 0) {
        if (n & 1)
            set_bits++;
        else
            unset_bits++;
        n >>= 1;
    }

    if (set_bits == unset_bits) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

// correct