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
    int n, k;
    cin >> n >> k;
    vector<int> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    set<int> st(arr.begin(), arr.end());

    int temp = arr[0];
    int dist = 0;
    queue<pair<int, int>> q;
    vector<bool> visited(n, false);
    q.push({ arr[0], 0 });
    while (!q.empty()) {
        int curr_node = q.front().first;
        int curr_dist = q.front().second;
        q.pop();
        visited[curr_node] = true;

        if (curr_dist > dist && st.count(curr_node)) {
            dist = curr_dist;
            temp = curr_node;
        }

        for (int neighbour : tree[curr_node]) {
            if (visited[neighbour]) continue;

            q.push({ neighbour, curr_dist + 1 });
        }
    }

    int d = 0;
    visited = vector<bool>(n, false);
    q.push({ temp, 0 });
    while (!q.empty()) {
        int curr_node = q.front().first;
        int curr_dist = q.front().second;
        q.pop();
        visited[curr_node] = true;

        if (curr_dist > d && st.count(curr_node)) {
            d = curr_dist;
        }

        for (int neighbour : tree[curr_node]) {
            if (visited[neighbour]) continue;

            q.push({ neighbour, curr_dist + 1 });
        }
    }

    cout << (d + 1) / 2 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}