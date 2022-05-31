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
        ll n;
        cin >> n;
        ll arr[n], s = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }

        bool flag = false;
        ld check_value = s / (ld)n;
        for (ll i = 0; i < n; i++) {
            if (check_value == arr[i]) {
                flag = true;
                break;
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
