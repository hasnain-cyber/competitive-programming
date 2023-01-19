#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

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
    int n;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end());

    double l = 0, h = 1e8;
    while (h - l > 1e-7) {
        double mid = l + (h - l) / (double)2;
        double max_value_left = -infinity_double, max_value_right = -infinity_double;
        for (int i = 0; i < n; i++) {
            double value = arr[i].second + abs(arr[i].first - mid);
            if (arr[i].first < mid) {
                max_value_left = max(max_value_left, value);
            } else {
                max_value_right = max(max_value_right, value);
            }
        }

        if (max_value_left < max_value_right) {
            l = mid + 1e-8;
        } else {
            h = mid;
        }
    }

    cout << setprecision(7) << l << endl;
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