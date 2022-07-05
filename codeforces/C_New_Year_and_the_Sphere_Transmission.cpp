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

int calculate_no_of_terms(int n, int k) {
    int ans;
    for (int factor : factors(k)) {
        if ((n * factor) % k == 0) return (n * factor) / k;
    }

    return n;
}

void solve_testcase() {
    int n;
    cin >> n;

    set<int> ans;
    for (int k = 1; k <= n; k++) {
        int z = calculate_no_of_terms(n, k);

        int m = (z - 1) / (n - 1);
        int total = k * ((n * (n - 1)) / 2) * m;

        int temp_value = z - m * n + m;
        total += k * ((temp_value * (temp_value - 1)) / 2);
        total += z;

        cout << k << " " << z << " " << total << endl;

        ans.insert(total);
    }

    for (int element : ans) cout << element << " ";
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