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
    int n, x;
    cin >> n >> x;

    string s;
    cin >> s;
    vector<pair<int, char>> v;
    for (int i = 0; i < n; i++) {
        if (v.empty() || v.back().second != s[i]) {
            v.push_back({1, s[i]});
        } else {
            v.back().first++;
        }
    }

    vector<int> temp_v;
    for (auto ele : v) {
        if (ele.second == '0') {
            temp_v.push_back(ele.first);
        }
    }
    sort(temp_v.begin(), temp_v.end());
    reverse(temp_v.begin(), temp_v.end());

    int cost = 0;
    int ans = 0;
    for (int value : temp_v) {
        if (cost + 2 * value + 1 <= x) {
            cost += 2 * value + 1;
            ans += value;
        } else {
            int rem = (x - cost - 1) / 2;
            ans += rem;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans++;
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