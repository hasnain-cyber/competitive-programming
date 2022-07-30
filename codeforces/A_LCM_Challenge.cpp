#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << 2 << endl;
        return;
    } else {
        if (n & 1) {
            cout << n * (n - 1) * (n - 2) << endl;
        } else {
            // shift by 1 to get odd;
            int ans = (n - 1) * (n - 2) * (n - 3);

            for (int i = max(n - 50, (int)1); i <= n; i++) {
                for (int j = max(n - 50, (int)1); j <= n; j++) {
                    for (int k = max(n - 50, (int)1); k <= n; k++) {
                        ans = max(ans, lcm(i, lcm(j, k)));
                    }
                }
            }

            cout << ans << endl;
        }
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