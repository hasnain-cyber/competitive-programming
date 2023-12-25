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

int find(int n) {
    int low = 0, high = INT_MAX, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        int val = 6 * mid * mid;
        if (val <= n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;

    int ans = 0;
    ans += find(n);
    n -= 6 * ans * ans;

    if (n <= 0) {
        cout << 3 * ans << endl;
    }
    else if (n - 4 * ans <= 0) {
        cout << 3 * ans + 1 << endl;
    }
    else if (n - 8 * ans - 2 <= 0) {
        cout << 3 * ans + 2 << endl;
    }
    else {
        cout << 3 * ans + 3 << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}