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
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        // check overlap
        if (l2 <= l1 && l1 <= r2) {
            cout << l1 << endl;
        } else if (l1 <= l2 && l2 <= r1) {
            cout << l2 << endl;
        } else {
            cout << l1 + l2 << endl;
        }
    }
}