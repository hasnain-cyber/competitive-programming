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
    int a, b;
    cin >> a >> b;

    if (b > a) {
        swap(a, b);
    }

    int d = a - b;
    int n = ceil((sqrt(1 + 8 * d) - 1) / (double)2);

    while ((b + (n * (n + 1)) / 2 - a) & 1) {
        n++;
    }

    cout << n << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}