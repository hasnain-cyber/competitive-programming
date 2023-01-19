// #include <bits/stdc++.h>

// #define MOD 1000000007
// // #define MOD 998244353
// #define infinity numeric_limits<int>::max()

// #define int long long int
// #define double long double
// #define pii pair<int, int>

// #define endl '\n'

// using namespace std;

// template <typename T>
// void print_arr(vector<T> &arr) {
//     for (T element : arr) {
//         cout << element << ' ';
//     }
//     cout << endl;
// }

// template <typename T>
// void sort_arr(vector<T> &arr) {
//     sort(arr.begin(), arr.end());
// }

// class UndirectedGraph {
//    private:
//     map<int, vector<int>> graph;
//     vector<int> vertex_degree;
//     vector<int> nNeighbours;
//     int nVertices;

//    public:
//     UndirectedGraph(int nVertices1) {
//         nVertices = nVertices1;
//         vertex_degree = vector<int>(nVertices + 1, 0);
//         nNeighbours = vector<int>(nVertices + 1, 0);
//     }

//     void add_edge(int u, int v) {
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//         nNeighbours[u]++;
//         nNeighbours[v]++;
//     }

//     void enumerate_vertices() {
//         queue<int> q;
//         for (int i = 1; i <= nVertices; i++) {
//             if (nNeighbours[i] == 1) {
//                 vertex_degree[i] = 1;
//                 q.push(i);
//             }
//         }

//         while (!q.empty()) {
//             auto curr = q.front();
//             q.pop();

//             for (auto neighbour : graph[curr]) {
//                 if (nNeighbours[neighbour] != 1) {
//                     nNeighbours[neighbour]--;
//                     if (nNeighbours[neighbour] == 1) {
//                         vertex_degree[neighbour] = vertex_degree[curr] + 1;
//                         q.push(neighbour);
//                     }
//                 }
//             }
//         }
//     }

//     int count_useful_vertices(int k) {
//         int count = 0;
//         for (int i = 1; i <= nVertices; i++) {
//             if (vertex_degree[i] > k) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };

// void solve_testcase() {
//     int n, k;
//     cin >> n >> k;

//     UndirectedGraph graph(n);
//     for (int i = 0; i < n - 1; i++) {
//         int u, v;
//         cin >> u >> v;
//         graph.add_edge(u, v);
//     }

//     graph.enumerate_vertices();
//     cout << graph.count_useful_vertices(k) << endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     for (int i = 0; i < t; i++) {
//         if (i == 36) {
//             int n, k;
//             cin >> n >> k;
//             string temp;
//             for (int i = 0; i < n - 1; i++) {
//                 int u, v;
//                 cin >> u >> v;
//                 temp.append(to_string(u) + to_string(v));
//             }
//             cout << temp << endl;
//         } else {
//             solve_testcase();
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std; 

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> g(n, vector<int>());
        vector<int> rem(n, 0);
        vector<int> layer(n, 0);

        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
            rem[x]++;
            rem[y]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (rem[i] == 1) {
                q.push(i);
                layer[i] = 1;
            }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (rem[v] != 1) {
                    rem[v]--;
                    if (rem[v] == 1) {
                        layer[v] = layer[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (layer[i] > k)
                ans++;

        cout << ans << '\n';
    }

    return 0;
}