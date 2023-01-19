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

vector<int> path;
vector<int> curr;
void dfs(int v, int k) {
    while (curr[v] < k) {
        int u = curr[v]++;
        dfs(u, k);
        path.push_back(u);
    }
}

void solve_testcase() {
    path.clear();
    curr = vector<int>(26, 0);

    int n, k;
    cin >> n >> k;

    dfs(0, k);
    print_arr(path);

    // cout << 'a';
    // for (int i = 0; i < n - 1; i++) {
    //     cout << (char)(path[i % path.size()] + 'a');
    // }
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