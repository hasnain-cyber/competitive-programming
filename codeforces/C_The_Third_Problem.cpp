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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int, int> range;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) range.first = i;
        else if (arr[i] == 1) range.second = i;
    }
    if (range.first > range.second) swap(range.first, range.second);

    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]] = i;

    int ans = 1, counter = 2;
    for (int i = 2; i < n; i++) {
        int index = mp[i];
        if (index < range.first || index > range.second) {
            range.first = min(range.first, index);
            range.second = max(range.second, index);
            counter++;
        }
        else {
            ans = (ans * ((range.second - range.first + 1) - counter)) % MOD;
            counter++;
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