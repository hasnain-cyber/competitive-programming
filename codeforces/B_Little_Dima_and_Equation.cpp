#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int check_sum_of_digits(int n, int s) {
    int check_value = 0;
    while (n > 0) {
        check_value += n % 10;
        n /= 10;
    }

    return check_value == s;
}

void solve_testcase() {
    int limit = pow(10, 9);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> ans;
    for (int s = 1; s <= 81; s++) {
        int x = b * pow(s, a) + c;

        if (x > 0 && x < limit && check_sum_of_digits(x, s)) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << endl;
    for (int ele : ans) cout << ele << " ";
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