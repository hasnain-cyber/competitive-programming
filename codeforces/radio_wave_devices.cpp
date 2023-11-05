#include <bits/stdc++.h>

using namespace std;

int rec(vector<vector<int>>& graph, int curr, vector<int>& freq, int parent, vector<int>& dp, int& ans) {
    if (dp[curr] != -1) return dp[curr];

    int mx = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int child : graph[curr]) {
        if (child == parent || abs(freq[curr] - freq[child]) > 1) continue;

        int value = rec(graph, child, freq, parent, dp, ans);
        pq.push(1 + value);
        if (pq.size() > 2) pq.pop();

        mx = max(mx, 1 + value);
    }

    if (pq.size() == 2) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        ans = max(ans, first + second + 1);
    }

    return dp[curr] = mx;
}

int solve(vector<int>& from, vector<int>& to, vector<int>& freq) {
    int n = freq.size();
    int m = from.size();

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        graph[from[i] - 1].push_back(to[i] - 1);
    }

    vector<int> dp(n, -1);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1 + rec(graph, i, freq, -1, dp, ans));
    }

    return ans;
}

int main() {
    // vector<int> network_from = { 1, 2, 3 };
    // vector<int> network_to = { 2, 3, 4 };
    // vector<int> freq = { 1, 3, 2, 1 };

    vector<int> network_from = { 1, 1, 1 };
    vector<int> network_to = { 2, 3, 4 };
    vector<int> freq = { 1, 1, 1, 1 };

    cout << solve(network_from, network_to, freq) - 1 << endl;
}