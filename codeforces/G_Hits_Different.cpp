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

int N = 1450;
vector<vector<int>> prefix_sum;
vector<int> ans(N *N + 5, 0);

void solve_testcase() {
    int n;
    cin >> n;
    cout << ans[n] << endl;
}

void init() {
    int counter = 1;
    vector<vector<int>> graph = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++, counter++) {
            graph[j][i - j] = counter * counter;
        }
    }

    // print graph
    // cout << "graph" << endl;
    // for (int i = 0; i < N; i++) {
    //     print_arr(graph[i]);
    // }

    // calculate prefix sum
    prefix_sum = vector<vector<int>>(N, vector<int>(N));
    prefix_sum[0][0] = graph[0][0];
    for (int i = 1; i < N; i++) {
        prefix_sum[i][0] = prefix_sum[i - 1][0] + graph[i][0];
        prefix_sum[0][i] = prefix_sum[0][i - 1] + graph[0][i];
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + graph[i][j];
        }
    }

    // print prefix sum
    // cout << "prefix sum" << endl;
    // for (int i = 0; i < N; i++) {
    //     print_arr(prefix_sum[i]);
    // }

    // works well until prefix sum. but then it gives wrong answer while calucating ans.

    counter = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++, counter++) {
            ans[counter] = prefix_sum[j][i - j];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}