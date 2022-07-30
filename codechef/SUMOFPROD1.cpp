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
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> reduced_arr;
    for (int i = 0; i < n; i++) {
        if (reduced_arr.empty() || reduced_arr.back().first != arr[i]) {
            reduced_arr.push_back({arr[i], 1});
        } else {
            reduced_arr.back().second++;
        }
    }

    int ans = 0;
    for (auto ele : reduced_arr) {
        if (ele.first == 0) continue;

        ans += (ele.second * (ele.second + 1)) / 2;
    }

    cout << ans << endl;
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