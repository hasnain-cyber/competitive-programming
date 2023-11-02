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

class DSU {
   private:
    int n;
    vector<int> parent;
    vector<int> size;

   public:
    DSU(int n1) {
        n = n1;
        parent = vector<int>(n);
        size = vector<int>(n);
    }

    void make(int v, int sz) {
        parent[v] = v;
        size[v] = sz;
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }

        // path compression
        return parent[v] = find(parent[v]);
    }

    int sz(int v) {
        return size[find(v)];
    }

    // union
    void unn(int u, int v) {
        int a = find(u);
        int b = find(v);

        if (a != b) {
            // union by size
            if (size[a] < size[b]) {
                swap(a, b);
            }

            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // connect in order which arr[i] - k * (i + 1) is greater
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i < n; i++) {
        pq.push({arr[i] - k * (i + 1), i});
    }

    DSU dsu(n);
    dsu.make(0, arr[0]);
    while (!pq.empty()) {
        int i = pq.top().second;
        pq.pop();

        dsu.make(i, arr[i]);
        if (i != 0) {
            int sz1 = dsu.sz(0);
            int sz2 = dsu.sz(i);

            if (sz1 + sz2 < (i + 1) * k) {
                cout << "No" << endl;
                return;
            }
            else {
                dsu.unn(i, 0);
            }
        }
    }

    cout << "Yes" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}