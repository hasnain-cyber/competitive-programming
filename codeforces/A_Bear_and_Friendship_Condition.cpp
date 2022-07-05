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
   private:
    vector<set<int>> graph;
    int n;

    bool divide_bipartite_dfs(int current_node, int current_color, vector<int> &vertices_colors, vector<bool> &visited) {
        vertices_colors[current_node] = current_color;
        visited[current_node] = true;

        int previous_color = current_color;
        current_color = (current_color + 1) % 2;

        for (int neighbour : graph[current_node]) {
            if (!visited[neighbour] && !divide_bipartite_dfs(neighbour, current_color, vertices_colors, visited)) {
                return false;
            } else {
                if (vertices_colors[neighbour] == previous_color)
                    return false;
            }
        }

        return true;
    }

    void connected_components_dfs(int current_node, vector<bool> &visited, vector<int> &current_component) {
        visited[current_node] = true;
        current_component.push_back(current_node);

        for (int neighbour : graph[current_node]) {
            if (!visited[neighbour]) {
                connected_components_dfs(neighbour, visited, current_component);
            }
        }
    }

   public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<set<int>>(n + 1);
    }

    void add_edge(int u, int v) {
        graph[u].insert(v);
        graph[v].insert(u);
    }

    bool is_isolated(int u) {
        return graph[u].size() == 0;
    }

    bool edge_exists(int u, int v) {
        return graph[u].count(v);
    }

    vector<int> divide_bipartite() {
        vector<bool> visited(n + 1, false);
        vector<int> vertices_colors(n + 1);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bool is_colorable = divide_bipartite_dfs(i, 0, vertices_colors, visited);
                if (!is_colorable) return {-1};
            }
        }

        return vertices_colors;
    }

    vector<vector<int>> connected_components() {
        vector<bool> visited(n + 1, false);

        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                vector<int> current_component;
                connected_components_dfs(i, visited, current_component);
                ans.push_back(current_component);
            }
        }

        return ans;
    }
};

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    UndirectedGraph graph = UndirectedGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }

    vector<vector<int>> connected_components = graph.connected_components();
    for (vector<int> component : connected_components) {
        int length = component.size();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (!graph.edge_exists(component[i], component[j])) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}