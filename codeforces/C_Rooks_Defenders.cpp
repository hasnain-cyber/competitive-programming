#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vector<ll> i_counter(n + 1, 0);
    vector<ll> j_counter(n + 1, 0);
    set<ll> targeted_i, targeted_j;

    for (int i = 1; i <= n; i++) {
        targeted_i.insert(i);
        targeted_j.insert(i);
    }

    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll i, j;
            cin >> i >> j;
            i_counter[i]++;
            if (i_counter[i] == 1) targeted_i.erase(i);
            j_counter[j]++;
            if (j_counter[j] == 1) targeted_j.erase(j);
        } else if (type == 2) {
            ll i, j;
            cin >> i >> j;
            i_counter[i]--;
            if (i_counter[i] == 0) targeted_i.insert(i);
            j_counter[j]--;
            if (j_counter[j] == 0) targeted_j.insert(j);
        } else {
            ll i1, i2, j1, j2;
            cin >> i1 >> j1 >> i2 >> j2;

            bool flag1 = targeted_i.lower_bound(i1) == targeted_i.upper_bound(i2);
            bool flag2 = targeted_j.lower_bound(j1) == targeted_j.upper_bound(j2);
            if (flag1 || flag2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}