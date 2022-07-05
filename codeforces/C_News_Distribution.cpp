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

   public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<vector<int>>(n + 1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void bfs(int start, vector<int> &ans, vector<bool> &visited) {
        visited[start] = true;

        queue<int> q;
        q.push(start);
        set<int> visited_this_run;
        int counter = 0;
        while (!q.empty()) {
            int element = q.front();
            counter++;
            visited_this_run.insert(element);
            q.pop();

            for (int neighbour : graph[element]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        for (int element : visited_this_run)
            ans[element] = counter;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;

        UndirectedGraph graph = UndirectedGraph(n);
        while (m--) {
            int size;
            cin >> size;

            vector<int> v;
            for (int i = 0; i < size; i++) {
                int temp;
                cin >> temp;
                v.push_back(temp);
            }
            for (int i = 0; i < size - 1; i++) graph.add_edge(v[i], v[i + 1]);
        }

        vector<bool> visited(n + 1, false);
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) graph.bfs(i, ans, visited);
        }

        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}