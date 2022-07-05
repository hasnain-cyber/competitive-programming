#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int get_higher_value(int n) {
    int k = ceil(log2(n));
    return pow(2, k);
}

void solve_testcase() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        mp[value]++;
    }

    int ans = 0;
    for (auto it : mp) {
        int higher_value = get_higher_value(it.first);
        if (higher_value == it.first) {
            ans += ((it.second) * (it.second - 1)) / 2;
        } else {
            int remaining_value = higher_value - it.first;
            if (mp.count(remaining_value)) {
                ans += (mp[remaining_value] * it.second);
            }
        }
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