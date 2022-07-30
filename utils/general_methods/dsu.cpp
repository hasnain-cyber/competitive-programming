#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

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

    void make(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v) {
        if (v == parent[v]) {
            return v;
        }

        // path compression
        return parent[v] = find(parent[v]);
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}