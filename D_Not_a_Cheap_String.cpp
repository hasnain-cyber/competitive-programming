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
    string arr;
    cin >> arr;
    int n = arr.size();
    int k;
    cin >> k;

    vector<pii> price_arr;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int value = (int)(arr[i] - 'a') + 1;
        price_arr.push_back({value, i});
        s += value;
    }
    sort(price_arr.begin(), price_arr.end());

    set<int> removed_indices;
    while (s > k) {
        pii last = price_arr.back();
        price_arr.pop_back();
        removed_indices.insert(last.second);
        s -= last.first;
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (!removed_indices.count(i)) {
            ans.push_back(arr[i]);
        }
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