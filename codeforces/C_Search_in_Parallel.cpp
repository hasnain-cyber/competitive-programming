#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    vector<int> ans1, ans2;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (s1 * (ans1.size() + 1) < s2 * (ans2.size() + 1)) {
            ans1.push_back(arr[i].second);
        } else {
            ans2.push_back(arr[i].second);
        }
    }

    cout << ans1.size() << " ";
    print_arr(ans1);
    cout << ans2.size() << " ";
    print_arr(ans2);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}