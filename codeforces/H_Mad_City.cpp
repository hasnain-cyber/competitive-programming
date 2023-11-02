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

class UndirectedGraph {
private:
    int n;
    vector<set<int>> graph;

    int detect_cycle(int curr, int parent, vector<bool>& visited) {
        visited[curr] = true;

        for (auto neighbour : graph[curr]) {
            if (neighbour == parent) continue;

            if (visited[neighbour]) return neighbour;
            int start = detect_cycle(neighbour, curr, visited);
            if (start != -1) return start;
        }

        return -1;
    }

    void cc(int curr, vector<int>& component, vector<bool>& visited) {
        component.push_back(curr);
        visited[curr] = true;

        for (auto neighbour : graph[curr]) {
            if (visited[neighbour]) continue;

            cc(neighbour, component, visited);
        }
    }

public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<set<int>>(n);
    }

    UndirectedGraph(vector<vector<int>> arr) {
        n = arr.size();
        for (int i = 0; i < n; i++) {
            set<int> temp;
            for (auto ele : arr[i]) temp.insert(ele);
            graph[i] = temp;
        }
    }

    void add_edge(int u, int v) {
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int detect_cycle() {
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int start_node = detect_cycle(i, -1, visited);
            if (start_node != -1) return start_node;
        }

        return -1;
    }

    vector<vector<int>> cc() {
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            vector<int> component;
            cc(i, component, visited);
            ans.push_back(component);
        }

        return ans;
    }

    int dist(int u, int v) {
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);

        q.push({ u, 0 });
        while (!q.empty()) {
            int curr_node = q.front().first;
            int curr_dist = q.front().second;
            q.pop();
            visited[curr_node] = true;

            if (curr_node == v) return curr_dist;

            for (auto neighbour : graph[curr_node]) {
                if (visited[neighbour]) continue;

                q.push({ neighbour, curr_dist + 1 });
            }
        }

        return -1;
    }

    bool check_if_in_cycle(int v) {
        if (detect_cycle() == -1) return false;

        vector<bool> visited = vector<bool>(n, false);
        stack<int> stk;
        stk.push(v);
        while (!stk.empty()) {
            int curr_node = stk.top();
            stk.pop();

            for (auto neighbour : graph[curr_node]) {
                if (visited[neighbour]) {
                    return neighbour == v;
                }
                visited[neighbour] = true;
                stk.push(neighbour);
            }
        }

        return false;
    }
};

void solve_testcase() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    UndirectedGraph graph(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph.add_edge(u, v);
    }

    if (a == b) {
        cout << "NO" << endl;
        return;
    }

    if (graph.check_if_in_cycle(b)) {
        cout << "YES" << endl;
        return;
    }

    int start_node = graph.detect_cycle();
    int d1 = graph.dist(start_node, a);
    int d2 = graph.dist(start_node, b);

    if (d1 <= d2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}