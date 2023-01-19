#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

class UndirectedGraph {
   private:
    map<int, vector<int>> graph;
    int nVertices;

   public:
    UndirectedGraph(int nVertices1) {
        nVertices = nVertices1;
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> get_connected_components() {
        vector<int> visited(nVertices + 1, 0);
        vector<vector<int>> cc;
        for (int i = 1; i <= nVertices; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                vector<int> temp_cc = {i};

                while (!q.empty()) {
                    int ele = q.front();
                    q.pop();

                    for (int neighbour : graph[ele]) {
                        if (!visited[neighbour]) {
                            q.push(neighbour);
                            visited[neighbour] = 1;
                            temp_cc.push_back(neighbour);
                        }
                    }
                }

                cc.push_back(temp_cc);
            }
        }
        return cc;
    }
};

int compare(vector<int> &v1, vector<int> &v2) {
    return v1.size() > v2.size();
}

void solve_testcase() {
    int n, d;
    cin >> n >> d;

    UndirectedGraph graph(n);
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        graph.add_edge(x, y);

        vector<vector<int>> cc = graph.get_connected_components();
        int required_edges = 0;
        for (vector<int> temp_cc : cc) {
            required_edges += (int)temp_cc.size() - 1;
        }

        int extra_edges = i + 1 - required_edges;
        sort(cc.begin(), cc.end(), compare);
        int len = 0;
        for (int i = 0; i < min(extra_edges + 1, (int)cc.size()); i++) {
            len += cc[i].size();
        }

        cout << len - 1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}