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

    int x = 0;
    for (int i = 1; i <= n - 2; i++) {
        x ^= i;
    }

    vector<int> ans;
    if (x == 0) {
        // just replace 1 with 0, when the xor of first n - 2 numbers is 0
        ans.push_back(0);
        for (int i = 2; i <= n - 2; i++) {
            ans.push_back(i);
        }
        x ^= 1;
        int k = log2(n - 2) + 1;
        ans.push_back(1 << k);
        ans.push_back((1 << k) ^ x);
    } else {
        for (int i = 1; i <= n - 2; i++) {
            ans.push_back(i);
        }
        int k = log2(n - 2) + 1;
        ans.push_back(1 << k);
        ans.push_back((1 << k) ^ x);
    }

    print_arr(ans);
    // find xor of all elements of arr
    // int xor_of_arr = 0;
    // for (int element : ans) {
    //     xor_of_arr ^= element;
    // }
    // cout << xor_of_arr << endl;
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