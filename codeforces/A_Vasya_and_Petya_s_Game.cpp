#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

vector<bool> seive(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) is_prime[j] = false;
        }
    }

    return is_prime;
}

void solve_testcase() {
    int n;
    cin >> n;

    vector<int> primes;
    vector<bool> primes_bool = seive(n);
    for (int i = 1; i <= n; i++) {
        if (primes_bool[i]) primes.push_back(i);
    }

    vector<int> ans;
    for (int prime : primes) {
        int current_value = prime;
        while (current_value <= n) {
            ans.push_back(current_value);
            current_value *= prime;
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