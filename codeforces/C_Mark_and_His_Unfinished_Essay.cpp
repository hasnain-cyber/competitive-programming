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
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    vector<pii> len(c), query(c);
    int curr = n;
    for (int i = 0; i < c; i++) {
        cin >> query[i].first >> query[i].second;
        int q_len = query[i].second - query[i].first + 1;

        len[i].first = curr + 1, len[i].second = curr + q_len;
        curr = len[i].second;
    }

    while (q--) {
        int idx;
        cin >> idx;

        for (int i = c - 1; i >= 0; i--) {
            if (idx >= len[i].first && idx <= len[i].second) {
                int gap = idx - len[i].first;
                idx = query[i].first + gap;
            }
        }

        cout << s[idx - 1] << endl;
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