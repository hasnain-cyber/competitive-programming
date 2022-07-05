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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int ans = 0;
    if (x > 0) {
        for (auto it : mp) {
            int element1 = it.first;
            int element2 = element1 ^ x;

            if (mp.count(element2)) {
                ans += it.second * mp[element2];
            }
        }
        
        cout << ans / 2 << endl;
    } else {
        for (auto it : mp) {
            ans += (it.second * (it.second - 1)) / 2;
        }

        cout << ans << endl;
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