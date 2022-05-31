#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    ll arr[n];

    ll count = 0, s = 0, min_value = MAX, max_value = MIN;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) count++;
        s += arr[i];

        min_value = min(min_value, s);
        max_value = max(max_value, s);
    }

    // cout << min_value << " " << max_value << endl;
    if (s < 0) {
        s = -s;
        min_value = -min_value;
        max_value = -max_value;
    }

    ll visited = max_value - min_value + 1;
    if (min_value > 0) visited += min_value;
    ll go_back_charges = ceil(s / (ld)k);

    // cout << go_back_charges << endl;

    ll remaining_charges = count - go_back_charges;

    // cout << remaining_charges << endl;

    if (remaining_charges < 0)
        cout << -1 << endl;
    else {
        visited += (remaining_charges / 2) * k;
        cout << visited << endl;
    }
}