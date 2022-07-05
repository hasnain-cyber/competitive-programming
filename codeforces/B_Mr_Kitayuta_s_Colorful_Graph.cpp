#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

class UndirectedGraph {
   public:
    vector<vector<int>> graph;
    map<pair<int, int>, set<int>> color_map;
    int n;

   public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<vector<int>>(n + 1);
    }

    void add_edge(int u, int v, int color) {
        graph[u].push_back(v);
        graph[v].push_back(u);

        color_map[{u, v}].insert(color);
        color_map[{v, u}].insert(color);
    }

    bool dfs(int u, int v, int color, vector<bool> &visited) {
        visited[u] = true;
        if (u == v) return true;

        for (int neighbour : graph[u]) {
            if (!visited[neighbour]) {
                if (color_map[{u, neighbour}].count(color) && dfs(neighbour, v, color, visited))
                    return true;
            }
        }

        return false;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    UndirectedGraph graph = UndirectedGraph(n);
    set<int> colors;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph.add_edge(u, v, c);

        colors.insert(c);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        int ans = 0;
        for (int color : colors) {
            vector<bool> visited(n + 1, false);
            if (graph.dfs(u, v, color, visited)) ans++;
        }
        cout << ans << endl;
    }
}