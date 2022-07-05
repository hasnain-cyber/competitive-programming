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
    int N = pow(10, 7);

    int n;
    cin >> n;
    vector<int> arr(N + 1, 0);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        arr[value]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        arr[i + 1] += arr[i] / 2;
        arr[i] %= 2;
        ans += arr[i];
    }

    cout << ans << endl;
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