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
    int n;
    cin >> n;
    vector<int> arr(n), pos, neg;
    int n_zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            n_zeros++;
        } else if (arr[i] > 0) {
            pos.push_back(arr[i]);
        } else {
            neg.push_back(arr[i]);
        }
    }

    if (n_zeros == n) {
        cout << "NO" << endl;
        return;
    }

    vector<int> ans;
    for (int i = 0; i < n_zeros; i++) {
        ans.push_back(0);
    }

    int current_sum = 0;
    while (ans.size() < n) {
        if (current_sum <= 0) {
            int value = pos.back();
            pos.pop_back();
            ans.push_back(value);
        } else {
            int value = neg.back();
            neg.pop_back();
            ans.push_back(value);
        }
        current_sum += ans.back();
    }

    cout << "YES" << endl;
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