#include <bits/stdc++.h>

using namespace std;

int main() {
    // vector<int> connection_from = { 0, 1 ,0 };
    // vector<int> connection_to = { 1, 2, 2 };
    // vector<int> connection_weight = { 10, 20, 50 };
    // vector<int> deliveries = { 1, 2 };
    // int k = 2;
    // int n = 3;

    vector<int> connection_from = { 0, 0, 4, 4, 1, 1 };
    vector<int> connection_to = { 1, 4, 1, 3, 2, 3 };
    vector<int> connection_weight = { 10, 3, 5, 4, 2, 4 };
    vector<int> deliveries = { 1, 3 };
    int k = 2;
    int n = 5;

    int m = connection_from.size();

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        graph[connection_from[i]].push_back({ connection_to[i], connection_weight[i] });
        graph[connection_to[i]].push_back({ connection_from[i], connection_weight[i] });
    }

    map<int, int> mp;
    for (int i = 0; i < k; i++) {
        mp[deliveries[i]] = (1 << i);
    }

    vector<vector<int>> dp(n, vector<int>((1 << k), -1));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, { 0, mp[0] } });
    while (!pq.empty()) {
        int curr_node = pq.top().second.first;
        int curr_visited = pq.top().second.second;
        int curr_weight = pq.top().first;
        pq.pop();

        dp[curr_node][curr_visited] = curr_weight;

        if (curr_node == 0 && __builtin_popcount(curr_visited) == k) {
            cout << curr_weight << endl;
            return 0;
        }

        for (auto neighbour : graph[curr_node]) {
            int next_node = neighbour.first;
            int next_weight = neighbour.second;

            int new_visited = curr_visited | mp[next_node];
            if (dp[next_node][new_visited] == -1 || dp[next_node][new_visited] > curr_weight + next_weight) {
                dp[next_node][new_visited] = curr_weight + next_weight;
                pq.push({ dp[next_node][new_visited], { next_node, new_visited } });
            }
        }
    }

    cout << -1 << endl;
}