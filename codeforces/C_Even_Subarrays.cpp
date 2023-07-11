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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int odd_subarr_count = 0;
    unordered_map<int, int> mp;
    for (int k = 0; k * k <= 2 * n; k++) {
        mp.clear();
        
        int xor_to_find = k * k;
        int curr_xor = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            curr_xor ^= arr[i];
            if (mp.find(curr_xor ^ xor_to_find) != mp.end()) {
                odd_subarr_count += mp[curr_xor ^ xor_to_find];
            }
            mp[curr_xor]++;
        }
    }

    cout << (n * (n + 1) / 2) - odd_subarr_count << endl;
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