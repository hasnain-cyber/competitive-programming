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

int count_digits(int n) {
    int ans = 0;
    while (n > 0) {
        n /= 10;
        ans++;
    }
    return ans;
}

void solve_testcase() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int a_low = pow(10, a - 1), a_high = pow(10, a) - 1;
    int b_low = pow(10, b - 1), b_high = pow(10, b) - 1;
    int c_low = pow(10, c - 1), c_high = pow(10, c) - 1;
    for (int a1 = a_low; a1 <= a_high; a1++) {
        int low = b_low, high = b_high, value_low = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (a1 + mid > c_high) {
                high = mid - 1;
            }
            else if (a1 + mid < c_low) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                value_low = mid;
            }
        }

        if (value_low == -1) continue;

        int low2 = value_low, high2 = b_high, value_high = -1;
        while (low2 <= high2) {
            int mid2 = low2 + (high2 - low2) / 2;

            if (a1 + mid2 > c_high) {
                high2 = mid2 - 1;
            }
            else if (a1 + mid2 < c_low) {
                low2 = mid2 + 1;
            }
            else {
                low2 = mid2 + 1;
                value_high = mid2;
            }
        }

        if (value_high == -1) continue;

        int range = value_high - value_low + 1;
        k -= range;
        if (k <= 0) {
            cout << a1 << " + " << value_high + k << " = " << a1 + value_high + k << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}