#include <bits/stdc++.h>

#define MOD 32768
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;
template <typename T>

void print_arr(vector<T> &arr) {
    for (T element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int fast_power(int a, int b, int mod = MOD) {
    if (b == 0) return 1;

    if (b & 1)
        return (a * (fast_power(a, b - 1, mod) % mod)) % mod;
    else
        return fast_power((a * a) % mod, b / 2, mod) % mod;
}

void solve_testcase() {
    int n;
    cin >> n;

    while (n--) {
        int value;
        cin >> value;

        int ans = infinity;
        for (int additions = 0; additions <= 15; additions++) {
            for (int multiplications = 0; multiplications <= 15; multiplications++) {
                int check_value = (value + additions) * (1 << multiplications);
                if (check_value % MOD == 0) {
                    ans = min(ans, additions + multiplications);
                }
            }
        }

        cout << ans << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}