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
        ll arr1[n];
        for (ll i = 0; i < n; i++) cin >> arr1[i];

        ll m;
        cin >> m;
        ll arr2[m];
        for (ll i = 0; i < m; i++) cin >> arr2[i];

        ll max_element1 = arr1[0], max_element2 = arr2[0];
        for (ll i = 0; i < n; i++) max_element1 = max(max_element1, arr1[i]);
        for (ll i = 0; i < m; i++) max_element2 = max(max_element2, arr2[i]);
        if (max_element1 > max_element2) {
            cout << "Alice" << endl;
            cout << "Alice" << endl;
        } else if (max_element1 < max_element2) {
            cout << "Bob" << endl;
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
            cout << "Bob" << endl;
        }
    }
}

// correct