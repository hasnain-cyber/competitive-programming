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

    set<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (st.count(arr[i])) {
            continue;
        } else {
            if (st.size() < 3) {
                st.insert(arr[i]);
            } else {
                ans++;
                st.clear();
                st.insert(arr[i]);
            }
        }
    }

    cout << ans + 1 << endl;
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