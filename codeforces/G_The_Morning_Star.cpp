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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    // check first case, north or south
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i].first]++;
    }
    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2;
    }

    // check for east or west
    mp.clear();
    for (int i = 0; i < n; i++) {
        mp[arr[i].second]++;
    }
    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2;
    }

    // diagonal directions 1
    mp.clear();
    for (int i = 0; i < n; i++) {
        int c = arr[i].first + arr[i].second;
        mp[c]++;
    }
    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2;
    }

    // diagonal directions 2
    mp.clear();
    for (int i = 0; i < n; i++) {
        int c = arr[i].first - arr[i].second;
        mp[c]++;
    }
    for (auto it : mp) {
        int count = it.second;
        ans += (count * (count - 1)) / 2;
    }

    cout << ans * 2 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}