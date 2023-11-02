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

void dfs(vector<vector<pair<int, int>>>& graph, int curr, vector<int>& dist, vector<bool>& visited, bool& flag) {
    visited[curr] = true;

    for (auto neighbour : graph[curr]) {
        if (visited[neighbour.first]) {
            if (dist[neighbour.first] != dist[curr] + neighbour.second) {
                flag = false;
                return;
            }
        }
        else {
            dist[neighbour.first] = dist[curr] + neighbour.second;
            dfs(graph, neighbour.first, dist, visited, flag);
        }
    }
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;

    int start_node = -1;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;

        graph[b].push_back({ a, d });
        graph[a].push_back({ b, -d });
    }

    vector<int> dist(n);
    vector<bool> visited(n, false);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(graph, i, dist, visited, flag);
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}