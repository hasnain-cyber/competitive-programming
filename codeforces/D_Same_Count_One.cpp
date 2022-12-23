#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<int> count_ones_arr(n, 0);
    int count_ones = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                count_ones++;
                count_ones_arr[i]++;
            }
        }
    }

    if (count_ones % n) {
        cout << -1 << endl;
        return;
    }

    int target = count_ones / n;
    vector<tuple<int, int, int>> ans;
    for (int j = 0; j < m; j++) {
        vector<int> increase_arr, decrease_arr;
        for (int i = 0; i < n; i++) {
            if (count_ones_arr[i] == target) {
                continue;
            } else if (count_ones_arr[i] < target && !arr[i][j]) {
                increase_arr.push_back(i);
            } else if (count_ones_arr[i] > target && arr[i][j]) {
                decrease_arr.push_back(i);
            }
        }

        for (int i = 0; i < min(increase_arr.size(), decrease_arr.size()); i++) {
            ans.push_back({increase_arr[i] + 1, decrease_arr[i] + 1, j + 1});
            count_ones_arr[increase_arr[i]]++;
            count_ones_arr[decrease_arr[i]]--;
        }
    }

    cout << ans.size() << endl;
    for (auto element : ans) {
        cout << get<0>(element) << " " << get<1>(element) << " " << get<2>(element) << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}