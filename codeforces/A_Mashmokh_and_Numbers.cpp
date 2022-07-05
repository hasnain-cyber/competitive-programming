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
    int n, k;
    cin >> n >> k;

    if (k < n / 2 || (n == 1 && k != 0)) {
        cout << -1 << endl;
        return;
    } else if (k == 0 && n == 1) {
        cout << 1 << endl;
        return;
    }

    int pairs = n / 2;
    int last_pair_gcd = k - (pairs - 1);

    int counter = 0, i = 1;
    while (counter < pairs - 1) {
        int first_number = i;
        int second_number = i + 1;

        if (first_number != last_pair_gcd && first_number != 2 * last_pair_gcd && second_number != last_pair_gcd && second_number != 2 * last_pair_gcd) {
            cout << first_number << " " << second_number << " ";
            counter++;
        }
        i += 2;
    }
    cout << last_pair_gcd << " " << 2 * last_pair_gcd << " ";
    if (n & 1) cout << (int)pow(10, 9) << " ";
    cout << endl;
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