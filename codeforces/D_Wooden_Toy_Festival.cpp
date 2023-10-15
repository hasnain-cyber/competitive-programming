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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (temp.empty() || arr[i] != temp.back()) temp.push_back(arr[i]);
    }

    if (temp.size() <= 3) {
        cout << 0 << endl;
        return;
    }

    int low = 0, high = infinity, ans = infinity;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int i = 0;
        while (i < n && arr[i] - arr[0] <= 2 * mid) i++;
        int j = n - 1;
        while (j >= 0 && arr[n - 1] - arr[j] <= 2 * mid) j--;


        if (i > j || arr[j] - arr[i] <= 2 * mid) {
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}