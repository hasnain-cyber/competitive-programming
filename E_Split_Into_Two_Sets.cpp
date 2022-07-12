#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;
template <typename T>

void print_arr(vector<T> &arr) {
    for (T element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

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

    bool detect_cycle_bfs(int current_node, int parent, vector<bool> &visited) {
        visited[current_node] = true;

        for (int neighbour : graph[current_node]) {
            if (neighbour == parent) continue;

            if (!visited[neighbour]) {
                return detect_cycle_bfs(neighbour, current_node, visited);
            } else {
                return true;
            }
        }

        return false;
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

    bool check_neighbours() {
        for (auto it : graph) {
            if (it.size() > 2) {
                return false;
            }
        }

        return true;
    }

    bool check2(map<pii, int> &mp) {
        for (auto it : mp) {
            if (it.second == 2) {
                if (graph[it.first.first].size() > 1) {
                    return false;
                } else if (graph[it.first.second].size() > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

void solve_testcase() {
    int n;
    cin >> n;
    UndirectedGraph graph = UndirectedGraph(n);

    map<pair<int, int>, int> mp;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);

        pair<int, int> p = {u, v};
        if (p.first > p.second) {
            swap(p.first, p.second);
        }
        mp[p]++;
        if (mp[p] > 2) {
            flag = false;
        }
    }

    if (!graph.check2(mp)) {
        flag = false;
    }

    vector<int> bip = graph.divide_bipartite();
    if (graph.check_neighbours() && bip[0] != -1 && flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}