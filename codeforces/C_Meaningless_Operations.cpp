#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

vector<int> factors(int n) {
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int f1 = i, f2 = n / i;
            ans.push_back(f1);
            if (f1 != f2) ans.push_back(f2);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;

    int k = log2(n) + 1;

    int ans = (1 << k) - 1;

    if (ans == n) {
        vector<int> factors_arr = factors(n);
        int size = factors_arr.size();

        cout << factors_arr[size - 2] << endl;
    } else
        cout << ans << endl;
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