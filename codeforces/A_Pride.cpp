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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int count_ones = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) count_ones++;
    }

    if (count_ones) {
        cout << n - count_ones << endl;
        return;
    } else {
        // find min length subarray whose gcd is one.
        int min_operations = MAX;
        for (int i = 0; i < n; i++) {
            int current_gcd = arr[i];
            for (int j = i; j < n; j++) {
                current_gcd = __gcd(current_gcd, arr[j]);
                if (current_gcd == 1) {
                    min_operations = min(min_operations, j - i);
                    break;
                }
            }
        }

        if (min_operations == MAX) {
            cout << -1 << endl;
            return;
        } else {
            cout << min_operations + n - 1 << endl;
            return;
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