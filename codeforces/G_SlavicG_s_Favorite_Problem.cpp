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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    set<int> st;
    vector<bool> visited(n, false);
    queue<pair<int, int>> q;
    q.push({a, 0});
    while (!q.empty()) {
        int curr_node = q.front().first;
        int curr_value = q.front().second;
        q.pop();

        if (curr_node == b) {
            if (curr_value != 0) continue;

            cout << "YES" << endl;
            return;
        }
        visited[curr_node] = true;
        st.insert(curr_value);

        for (auto neighbour : graph[curr_node]) {
            if (visited[neighbour.first]) continue;

            q.push({ neighbour.first, curr_value ^ neighbour.second });
        }
    }

    q.push({ b, 0 });
    visited = vector<bool>(n, false);
    while (!q.empty()) {
        int curr_node = q.front().first;
        int curr_value = q.front().second;
        q.pop();
        visited[curr_node] = true;
        if (curr_node != b && st.count(curr_value)) {
            cout << "YES" << endl;
            return;
        }

        for (auto neighbour : graph[curr_node]) {
            if (visited[neighbour.first]) continue;

            q.push({ neighbour.first, curr_value ^ neighbour.second });
        }
    }

    cout << "NO" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}