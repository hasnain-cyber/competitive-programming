#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

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
    string s;
    cin >> s;

    vector<string> permutaitons = {"abc", "acb", "bac", "bca", "cab", "cba"};
    vector<vector<int>> prefix_sum(6, vector<int>(n));
    for (int i = 0; i < 6; i++) {
        string permutation = permutaitons[i];
        int curr_index = 0, curr_sum = 0;
        for (int j = 0; j < n; j++) {
            char curr_char = permutation[curr_index % 3];
            curr_index++;

            if (s[j] != curr_char) {
                curr_sum++;
            }
            prefix_sum[i][j] = curr_sum;
        }
    }

    for (int i = 0; i < m; i++) {
        int min_value = infinity;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int i = 0; i < 6; i++) {
            int value;
            if (l == 0) {
                value = prefix_sum[i][r];
            } else {
                value = prefix_sum[i][r] - prefix_sum[i][l - 1];
            }
            min_value = min(min_value, value);
        }
        cout << min_value << endl;
    }
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