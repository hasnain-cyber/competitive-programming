#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element;
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start;
    int empty_cells = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') {
                start = {i, j};
                empty_cells++;
            }
        }
    }

    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int to_save = empty_cells- k;
    if (to_save > 0) {
        q.push(start);
        visited[start.first][start.second] = true;
        int counter = 1;
        while (!q.empty() && counter < to_save) {
            pii curr = q.front();
            q.pop();

            int di[] = {-1, 1, 0, 0};
            int dj[] = {0, 0, -1, 1};
            for (int z = 0; z < 4 && counter < to_save; z++) {
                int i2 = curr.first + di[z];
                int j2 = curr.second + dj[z];
                if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && !visited[i2][j2] && arr[i2][j2] != '#') {
                    visited[i2][j2] = true;
                    counter++;
                    q.push({i2, j2});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#') {
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                arr[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        print_arr(arr[i]);
    }
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