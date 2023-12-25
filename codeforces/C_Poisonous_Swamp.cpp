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
    int n;
    cin >> n;
    vector<string> arr(2);
    for (int i = 0; i < 2; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;

            if (arr[i][j] == '*') {
                queue<pair<int, int>> q;
                q.push({ i, j });
                visited[i][j] = true;
                int counter = 0;
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    int i = curr.first;
                    int j = curr.second;

                    counter++;

                    int di[] = { 0, 0, 1, -1 };
                    int dj[] = { 1, -1, 0, 0 };
                    for (int k = 0; k < 4; k++) {
                        int i2 = i + di[k];
                        int j2 = j + dj[k];
                        if (i2 < 0 || i2 >= 2 || j2 < 0 || j2 >= n || arr[i2][j2] != '*' || visited[i2][j2]) continue;
                        
                        q.push({ i2, j2 });
                        visited[i2][j2] = true;
                    }
                }

                ans += counter - 1;
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}