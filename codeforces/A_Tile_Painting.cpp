#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

set<int> prime_factors(int n) {
    set<int> ans;

    while (n % 2 == 0) {
        n /= 2;
        ans.insert(2);
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            ans.insert(i);
            n /= i;
        }
    }

    if (n > 2) ans.insert(n);
    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    set<int> factors = prime_factors(n);
    if (factors.size() == 1) {
        cout << *factors.begin() << endl;
        return;
    }

    cout << 1 << endl;
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