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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    a[0] = 1;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int low = 0, high = n, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        vector<int> new_a, new_b;
        for (int i = 0; i < n - mid; i++) new_a.push_back(a[i]);
        for (int i = mid; i < n; i++) new_b.push_back(b[i]);

        bool flag = true;
        for (int i = 0; i < n - mid; i++) {
            if (new_a[i] >= new_b[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = mid;
            high = mid - 1;
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