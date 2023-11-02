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

int solve(int right) {
    int highest_bit = 0;
    int ans = 0;
    while (pow(2, highest_bit) <= right) {
        // count no.s with highest_bit set
        int low = pow(2, highest_bit);
        int high = min((int)pow(2, highest_bit + 1) - 1, right);
        int count = high - low + 1;

        ans += count * (highest_bit);
        highest_bit++;
    }

    return ans;
}

void solve_testcase() {
    int l, r;
    cin >> l >> r;

    int ans = solve(r) - solve(l - 1);
    // cout << solve(r) << ' ' << solve(l - 1) << endl;
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}