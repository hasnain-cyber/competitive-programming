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
    int n, m;
    cin >> n >> m;

    int k = log2(n) + 1;
    vector<int> bits(k);

    int current_set_bits = 0;
    for (int i = 0; i < k; i++) {
        // check if i'th bit is set
        int mask = (1 << i);
        if (mask & n) {
            bits[i]++;
            current_set_bits++;
        }
    }

    if (current_set_bits > m) {
        cout << "NO" << endl;
    } else {
        for (int i = k - 1; i >= 1; i--) {
            while (bits[i] > 0 && current_set_bits < m) {
                current_set_bits++;
                bits[i]--;
                bits[i - 1] += 2;
            }
        }

        if (current_set_bits < m) {
            cout << "NO" << endl;
            return;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < k; i++) {
                while (bits[i] > 0) {
                    cout << (1 << i) << " ";
                    bits[i]--;
                }
            }
            cout << endl;
        }
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