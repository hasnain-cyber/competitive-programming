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

    vector<int> indices;
    vector<int> values;
    for (int i = 0; i < n; i++) {
        if (arr[i] < (i + 1)) {
            indices.push_back(i + 1);
            values.push_back(arr[i]);
        }
    }
    sort_arr(values);

    int sz = values.size();
    int ans = 0;
    for (int i : indices) {
        int index = upper_bound(values.begin(), values.end(), i) - values.begin();
        ans += sz - index;
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