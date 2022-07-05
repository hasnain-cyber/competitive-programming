#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void dfs(ll current, map<ll, vector<ll>> &edges_map, map<pair<ll, ll>, ll> &weight_map, set<ll> &visited, ll &current_prime) {
    visited.insert(current);

    vector<ll> neighbours = edges_map[current];
    for (ll neighbour : neighbours) {
        if (!visited.count(neighbour)) {
            weight_map[{current, neighbour}] = current_prime;
            weight_map[{neighbour, current}] = current_prime;

            if (current_prime == 2)
                current_prime = 3;
            else
                current_prime = 2;

            dfs(neighbour, edges_map, weight_map, visited, current_prime);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        // get edges
        vector<pair<ll, ll>> edges;
        map<ll, vector<ll>> mp;
        for (ll i = 0; i < n - 1; i++) {
            pair<ll, ll> temp;
            cin >> temp.first >> temp.second;
            edges.push_back(temp);
            mp[temp.first].push_back(temp.second);
            mp[temp.second].push_back(temp.first);
        }

        bool flag = true;
        for (auto element : mp) {
            if (element.second.size() > 2) {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << -1 << endl;
        else {
            // a map to store ans to every edge.
            map<pair<ll, ll>, ll> weight_map;

            for (auto element : mp) {
                if (element.second.size() == 1) {
                    set<ll> visited;
                    ll current_prime = 2;
                    dfs(element.first, mp, weight_map, visited, current_prime);
                    break;
                }
            }

            for (ll i = 0; i < edges.size(); i++) cout << weight_map[edges[i]] << " ";
            cout << endl;
        }
    }
}