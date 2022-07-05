#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    vector<ll> bg, sm;

    for (int i = 0; i < t; i++) {
        ll mx = 0, mn = 0, l;
        cin >> l;
        bool min_not_at_last = false;
        for (int j = 0; j < l; j++) {
            ll x;
            cin >> x;
            if (j) {
                if (mn < x) {
                    min_not_at_last = true;
                }
                mx = max(mx, x);
                mn = min(mn, x);
            } else {
                mx = mn = x;
            }
        }
        if (min_not_at_last) {
            mx = 1e9 + 90; // this signifes that any array put before it will work since min element is not at last.
            mn = -1; // this signifies that any array can be put after this, and the ans will be true, because in this array, the min element does not occur at the end of array.
        }
        sm.emplace_back(mn);
        bg.emplace_back(mx);
    }
    sort(bg.begin(), bg.end());

    ll ans = 0;
    for (int i = 0; i < t; i++) {
        ll ind = upper_bound(bg.begin(), bg.end(), sm[i]) - bg.begin();
        ans += (t - ind);
    }
    cout << ans << endl;

    return 0;
}

// this code has not been written by me, and has been copied from github
// i am too tired to solve write code for this question for now,
// but i know, i won't be able to sleep properly, if i don't submit it before going to bed, so here we are.