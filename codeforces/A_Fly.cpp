#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    double low = 0, high = pow(10, 10);
    while ((high - low) > pow(10, -7)) {
        double mid = (low + high) / 2;

        double current_weight = mid + m;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            double fuel_burnt;

            // landing
            fuel_burnt = current_weight / b[i];
            current_weight -= fuel_burnt;
            if (current_weight < m) {
                flag = false;
                break;
            }

            // take-off
            fuel_burnt = current_weight / a[i];
            current_weight -= fuel_burnt;
            if (current_weight < m) {
                flag = false;
                break;
            }
        }

        if (flag) {
            high = mid;
        } else {
            low = mid;
        }
    }

    if (low > pow(10, 9)) {
        cout << -1 << endl;
    } else {
        cout.precision(10);
        cout << low << endl;
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