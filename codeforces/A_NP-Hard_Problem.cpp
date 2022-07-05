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
    vector<vector<int>> graph;
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

   public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<vector<int>>(n + 1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool is_isolated(int u) {
        return graph[u].size() == 0;
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

    vector<int> color_arr = graph.divide_bipartite();
    if (color_arr[0] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> v1, v2;
        for (int i = 1; i <= n; i++) {
            if (color_arr[i] && !graph.is_isolated(i))
                v1.push_back(i);
            else if (!graph.is_isolated(i))
                v2.push_back(i);
        }

        cout << v1.size() << endl;
        for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
        cout << endl;
    }
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