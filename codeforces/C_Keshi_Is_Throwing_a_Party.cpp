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
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
        cin >> arr[i].first;
    }

    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].first >= counter && arr[i].second >= mid - 1 - counter) counter++;
        }

        if (counter >= mid) {
            low = mid + 1;
            ans = mid;
        }
        else {
            high = mid - 1;
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