#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char current = arr[i][j];
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            stack<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                pair<int, int> current_cell = q.top();
                q.pop();
                visited[current_cell.first][current_cell.second] = true;

                // get neighbours
                int di[] = {-1, 1, 0, 0};
                int dj[] = {0, 0, -1, 1};
                int adjacent_count = 0, new_count = 0;
                for (int k = 0; k < 4; k++) {
                    int i2 = current_cell.first + di[k];
                    int j2 = current_cell.second + dj[k];

                    if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m) continue;
                    if (arr[i2][j2] == current) {
                        adjacent_count++;
                        if (!visited[i2][j2]) {
                            q.push({i2, j2});
                            new_count++;
                        }
                    }
                }

                if (adjacent_count >= 2 && new_count == 0) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "No" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}