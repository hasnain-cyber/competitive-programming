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
    int n, k;
    cin >> n >> k;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (k > n - i) {
            ans[i] = 1000;
            k = k - (n - i);
        } else {
            ans[i] = k;
            // fill the next (k - 1) elements with -1
            for (int j = i + 1; j < i + k; j++) {
                ans[j] = -1;
            }
            // fill the remaining elements with -2
            for (int j = i + k; j < n; j++) {
                ans[j] = -2;
            }
            break;
        }
    }

    print_arr(ans);
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