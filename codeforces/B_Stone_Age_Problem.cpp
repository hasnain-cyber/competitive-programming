#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    ll s = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    set<ll> set_indices;
    for (ll i = 0; i < n; i++) {
        set_indices.insert(i);
    }

    ll current_all_value;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll position, new_value;
            cin >> position >> new_value;

            if (set_indices.count(position - 1)) {
                s += new_value - arr[position - 1];
                arr[position - 1] = new_value;
            } else {
                s += new_value - current_all_value;
                arr[position - 1] = new_value;
                set_indices.insert(position - 1);
            }
        } else {
            cin >> current_all_value;
            s = n * current_all_value;
            set_indices.clear();
        }
        cout << s << endl;
    }
}

// correct