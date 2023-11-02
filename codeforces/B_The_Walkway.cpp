#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> arr(m + 2);
    arr[0] = -d + 1;
    for (int i = 0; i < m; i++) cin >> arr[i + 1];
    arr[m + 1] = n + 1;

    m = m + 2;
    int consumed = m - 2;
    for (int i = 1; i < m; i++) {
        int value = (arr[i] - arr[i - 1] - 1) / d;
        consumed += value;
    }

    int final_consumed = consumed;
    for (int i = 1; i < m - 1; i++) {
        int change = -(arr[i] - arr[i - 1] - 1) / d - (arr[i + 1] - arr[i] - 1) / d + (arr[i + 1] - arr[i - 1] - 1) / d - 1;
        final_consumed = min(final_consumed, consumed + change);
    }

    int counter = 0;
    for (int i = 1; i < m - 1; i++) {
        int change = -(arr[i] - arr[i - 1] - 1) / d - (arr[i + 1] - arr[i] - 1) / d + (arr[i + 1] - arr[i - 1] - 1) / d - 1;
        if (consumed + change == final_consumed) counter++;
    }

    cout << final_consumed << " " << counter << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}