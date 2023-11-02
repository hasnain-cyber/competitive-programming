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
    vector<vector<int>> arr(n);
    vector<int> combined_arr;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        arr[i] = vector<int>(m);
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            combined_arr.push_back(arr[i][j]);
        }
    }
    sort(combined_arr.begin(), combined_arr.end());

    int splits = 0;
    for (int i = 0; i < n; i++) {
        int m = arr[i].size();
        for (int j = 0; j < m - 1; j++) {
            int idx1 = lower_bound(combined_arr.begin(), combined_arr.end(), arr[i][j]) - combined_arr.begin();
            int idx2 = lower_bound(combined_arr.begin(), combined_arr.end(), arr[i][j + 1]) - combined_arr.begin();

            if (idx1 + 1 != idx2) splits++;
        }
    }

    cout << splits << " " << n + splits - 1 << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}