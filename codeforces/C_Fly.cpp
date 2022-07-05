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
    vector<int> take_off_coefficients(n);
    for (int i = 0; i < n; i++) cin >> take_off_coefficients[i];
    vector<int> landing_coefficients(n);
    for (int i = 0; i < n; i++) cin >> landing_coefficients[i];

    // solved using binary search.

    double l = 0, h = pow(10, 10);
    while (l <= h) {
        double mid = (l + h) / 2;

        // check this value
        double current_weight = mid + m;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                double landing_weight_lost = current_weight / landing_coefficients[i];
                current_weight -= landing_weight_lost;
                if (current_weight < m) {
                    flag = false;
                    break;
                }
            }

            double take_off_weight_lost = current_weight / take_off_coefficients[i];
            current_weight -= take_off_weight_lost;
            if (current_weight < m) {
                flag = false;
                break;
            }

            if (i == n - 1) {
                double landing_weight_lost = current_weight / landing_coefficients[0];
                current_weight -= landing_weight_lost;
                if (current_weight < m) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            h = mid - pow(10, -7);
        } else {
            l = mid + pow(10, -7);
        }
    }

    double ans = (l + h) / 2;

    cout.precision(10);
    if (ans <= pow(10, 9) + 1)
        cout << ans << endl;
    else
        cout << -1 << endl;
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