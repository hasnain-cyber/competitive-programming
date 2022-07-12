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
    for (T element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        mp[value].push_back(i);
    }

    while (k--) {
        int a, b;
        cin >> a >> b;

        if (!mp.count(a) || !mp.count(b)) {
            cout << "NO" << endl;
            continue;
        }

        if (mp[a][0] <= mp[b][mp[b].size() - 1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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