#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int lis(vector<int> &arr) {
    if (arr.size() == 0)
        return 0;

    vector<int> tail(arr.size(), 0);
    int length = 1;

    tail[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        auto b = tail.begin(), e = tail.begin() + length;
        auto it = lower_bound(b, e, arr[i]);

        if (it == tail.begin() + length)
            tail[length++] = arr[i];
        else
            *it = arr[i];
    }

    return length;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << lis(arr) << endl;
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