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
    map<int, set<int>> graph;
    int nVertices;

   public:
    UndirectedGraph(int nVertices1) {
        nVertices = nVertices1;
    }

    void add_edge(int u, int v) {
        graph[u].insert(v);
        graph[v].insert(u);
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

    int get_n_bamboos() {
        int n_bamboos = 0;
        vector<vector<int>> cc = get_connected_components();
        for (vector<int> component : cc) {
            for (int ele : component) {
                if (graph[ele].size() == 1) {
                    n_bamboos++;
                    break;
                }
            }
        }

        return n_bamboos;
    }
};

void solve_testcase() {
    int n;
    cin >> n;
    UndirectedGraph g(n);
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        g.add_edge(i, u);
    }

    int n_cc = g.get_connected_components().size();
    int n_bamboos = g.get_n_bamboos();
    int n_cycles = n_cc - n_bamboos;

    int min_answer = n_cycles + min(n_bamboos, (int)1);
    int max_answer = n_cc;
    cout << min_answer << ' ' << max_answer << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}