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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ms.insert(arr[i]);
    }
    vector<int> prefix_sum(n);
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int sum_m = prefix_sum[m - 1];
    for (int i = 0; i < n; i++) {
        if (prefix_sum[i] > sum_m){
            continue;
        } 
        
    }
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