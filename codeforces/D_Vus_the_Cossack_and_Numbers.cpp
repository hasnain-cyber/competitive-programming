#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<double> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> ans(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        ans[i] = floor(arr[i]);
        s += ans[i];
    }

    int i = 0;
    while (s != 0) {
        while ((int)arr[i] == arr[i]) i++;
        ans[i]++;
        s++;
        i++;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << endl;
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