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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s = 0, max_element = MIN;
    for (int i = 0; i < n; i++) {
        s += arr[i];
        max_element = max(max_element, arr[i]);
    }

    if ((s & 1) || 2 * max_element > s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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