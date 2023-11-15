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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[i] = { u, v };
    }

    int v = -1;
    for (int i = 0; i < n; i++) {
        if (graph[i].size() < n - 1) {
            v = i;
            break;
        }
    }

    vector<int> ans(m);
    int n_colors;
    if (v == -1) {
        // take any edge and color it with two colors, taking 0
        n_colors = 3;
        int counter = 0;
        for (int i = 0; i < m; i++) {
            auto edge = edges[i];
            if (edge.first == 0 || edge.second == 0) {
                ans[i] = ((counter & 1) ? 1 : 2);
                counter++;
            }
            else {
                ans[i] = 3;
            }
        }
    }
    else {
        n_colors = 2;
        for (int i = 0; i < m; i++) {
            auto edge = edges[i];
            if (edge.first == v || edge.second == v) {
                ans[i] = 1;
            }
            else {
                ans[i] = 2;
            }
        }
    }

    cout << n_colors << endl;
    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}