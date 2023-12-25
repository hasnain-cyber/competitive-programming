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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++) {
        left[i] = arr[i] + (n - i - 1);
        right[i] = arr[i] + i;
    }

    for (int i = 0; i < n; i++) {
        left[i] = max(left[i], (i > 0 ? left[i - 1] : 0));
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = max(right[i], (i < n - 1 ? right[i + 1] : 0));
    }

    int ans = infinity;
    for (int i = 0; i < n; i++) {
        int value;
        if (i > 0 && i < n - 1)
            value = max(left[i - 1], right[i + 1]);
        else if (i > 0)
            value = left[i - 1];
        else if (i < n - 1)
            value = right[i + 1];
        else
            value = 0;
        
        ans = min(ans, max(arr[i], value));
    }
    cout << ans << endl;

}

int32_t main() {
    int t = 1;
    while (t--) {
        solve_testcase();
    }
}