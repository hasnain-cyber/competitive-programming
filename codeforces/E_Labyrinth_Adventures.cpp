#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll find_layer(pair<ll, ll> pos) {
    return max(pos.first, pos.second);
}

ll find_distance(pair<ll, ll> p1, pair<ll, ll> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

ll solve(pair<ll, ll> current, pair<ll, ll> end, pair<pair<ll, ll>, pair<ll, ll>> doors[], map<pair<pair<ll, ll>, pair<ll, ll>>, ll> &dp) {
    ll current_layer = find_layer(current);
    ll target_layer = find_layer(end);

    if (current_layer == target_layer)
        return find_distance(current, end);
    else {
        if (target_layer > current_layer) {
            pair<ll, ll> top_door = doors[current_layer].first;
            pair<ll, ll> right_door = doors[current_layer].second;

            if (!dp.count(make_pair(make_pair(top_door.first + 1, top_door.second), end)))
                dp[make_pair(make_pair(top_door.first + 1, top_door.second), end)] = solve(make_pair(top_door.first + 1, top_door.second), end, doors, dp);
            if (!dp.count(make_pair(make_pair(right_door.first, right_door.second + 1), end)))
                dp[make_pair(make_pair(right_door.first, right_door.second + 1), end)] = solve(make_pair(right_door.first, right_door.second + 1), end, doors, dp);

            return min(find_distance(current, top_door) + 1 + dp[make_pair(make_pair(top_door.first + 1, top_door.second), end)], find_distance(current, right_door) + 1 + dp[make_pair(make_pair(right_door.first, right_door.second + 1), end)]);
        }

        else {
            pair<ll, ll> top_door = doors[current_layer - 1].first;
            pair<ll, ll> right_door = doors[current_layer - 1].second;

            if (!dp.count(make_pair(top_door, end)))
                dp[make_pair(top_door, end)] = solve(top_door, end, doors, dp);
            if (!dp.count(make_pair(right_door, end)))
                dp[make_pair(right_door, end)] = solve(right_door, end, doors, dp);

            return min(find_distance(current, make_pair(top_door.first + 1, top_door.second)) + 1 + dp[make_pair(top_door, end)], find_distance(current, make_pair(right_door.first, right_door.second + 1)) + 1 + dp[make_pair(right_door, end)]);
        }
    }
}

int main() {
    ll n_layers;
    cin >> n_layers;

    pair<pair<ll, ll>, pair<ll, ll>> doors[n_layers - 1];
    for (ll i = 0; i < n_layers - 1; i++) {
        pair<pair<ll, ll>, pair<ll, ll>> temp;
        cin >> temp.first.first >> temp.first.second >> temp.second.first >> temp.second.second;
        temp.first.first -= 1;
        temp.first.second -= 1;
        temp.second.first -= 1;
        temp.second.second -= 1;
        doors[i] = temp;
    }

    map<pair<pair<ll, ll>, pair<ll, ll>>, ll> dp;
    ll queries;
    cin >> queries;
    while (queries--) {
        pair<ll, ll> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;
        start.first -= 1;
        start.second -= 1;
        end.first -= 1;
        end.second -= 1;

        cout << solve(start, end, doors, dp) << endl;
    }
}