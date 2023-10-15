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
    int n, q;
    cin >> n >> q;
    int N = 1005;
    vector<vector<int>> pre(N, vector<int>(N, 0));
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        pre[h][w] += h * w;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i > 0 && j > 0) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            else if (i > 0) pre[i][j] += pre[i - 1][j];
            else if (j > 0) pre[i][j] += pre[i][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;

        int ans = pre[hb - 1][wb - 1] - pre[hb - 1][ws] - pre[hs][wb - 1] + pre[hs][ws];
        cout << ans << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}