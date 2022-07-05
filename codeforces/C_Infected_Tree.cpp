#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll size(ll current, map<ll, vector<ll>> &mp, ll parent, map<ll, ll> &size_map) {
    // if doesn't have any child
    ll ans = 1;
    for (ll child : mp[current]) {
        if (child != parent) {
            if (!size_map.count(child)) size_map[child] = size(child, mp, current, size_map);
            ans += size_map[child];
        }
    }

    size_map[current] = ans;
    return size_map[current];
}

ll solve(ll current, map<ll, vector<ll>> &mp, ll parent, map<ll, ll> &size_map) {
    if (current == 1) {
        if (mp[current].size() == 1) return size_map[1] - 2;

        ll child1 = mp[current][0], child2 = mp[current][1];
        if (mp[current].size() == 2) return max(solve(child1, mp, current, size_map) + size_map[child2] - 1, solve(child2, mp, current, size_map) + size_map[child1] - 1);
    }

    // is leaf node
    if (mp[current].size() == 1) return 0;

    // has only one child, and one parent
    if (mp[current].size() == 2) {
        for (ll child : mp[current]) {
            if (child != parent) return size_map[child] - 1;
        }
    }

    // if has two children, and one parent
    ll ans = 0;
    for (ll child1 : mp[current]) {
        if (child1 != parent) {
            for (ll child2 : mp[current]) {
                if (child1 != child2 && parent != child2) {
                    ans = max(ans, solve(child1, mp, current, size_map) + size_map[child2] - 1);
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        map<ll, vector<ll>> mp;
        for (ll i = 0; i < n - 1; i++) {
            ll parent, child;
            cin >> parent >> child;
            mp[parent].push_back(child);
            mp[child].push_back(parent);
        }

        map<ll, ll> size_map;
        size(1, mp, -1, size_map);

        cout << solve(1, mp, -1, size_map) << endl;
    }
}