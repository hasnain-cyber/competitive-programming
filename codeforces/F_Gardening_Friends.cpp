#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

int dfs(int curr, vector<vector<int>>& graph, int parent, int depth, int& ans, int l, int c) {
    vector<int> max_dist = { 0, 0 };
    for (int child : graph[curr]) {
        if (child == parent) continue;

        int dist = 1 + dfs(child, graph, curr, depth + 1, ans, l, c);
        max_dist[1] = max(max_dist[1], dist);
        sort(max_dist.begin(), max_dist.end());
        reverse(max_dist.begin(), max_dist.end());
    }

    ans = max(ans, max_dist[0] * l - depth * c);
    ans = max(ans, (max_dist[0] + max_dist[1]) * l - max_dist[1] * c - depth * c);
    return max_dist[0];
}

void solve_testcase() {
    int n, l, c;
    cin >> n >> l >> c;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    dfs(0, graph, -1, 0, ans, l, c);
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}