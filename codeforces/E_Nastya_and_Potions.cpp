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

int solve(vector<int>& cost, vector<vector<int>>& graph, int curr, vector<bool>& visited) {
    if ((graph[curr].size() == 0) || visited[curr]) return cost[curr];
    visited[curr] = true;

    int ans = 0;
    for (int ele : graph[curr]) {
        ans += solve(cost, graph, ele, visited);
    }
    return cost[curr] = min(cost[curr], ans);
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    
    for (int i = 0; i < k; i++) {
        int ele;
        cin >> ele;
        ele--;
        cost[ele] = 0;
    }

    vector<vector<int>> graph(n);
    for (int u = 0; u < n; u++) {
        int count;
        cin >> count;
        for (int i = 0; i < count; i++) {
            int v;
            cin >> v;
            v--;
            graph[u].push_back(v);
        }
    }

    vector<int> ans(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        ans[i] = solve(cost, graph, i, visited);
    }

    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}