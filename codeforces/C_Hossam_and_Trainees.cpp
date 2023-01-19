#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() {
    ios::sync_with_stdio(0);

    int N = sqrt(1e9 + 7);

    vector<int> primes;
    vector<bool> is_prime(N, true);
    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = p; i <= N; i += p)
                is_prime[i] = false;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            int k = a[i];
            for (auto j : primes) {
                if (!(a[i] % j)) {
                    if (mp[j]) {
                        cout << "YES\n";
                        goto aaa;
                    }
                    mp[j] = 1;
                    while (!(k % j)) k /= j;
                }
            }
            if (k - 1 && mp[k]) {
                cout << "YES\n";
                goto aaa;
            }
            mp[k]++;
        }
        cout << "NO\n";
    aaa:;
    }
}