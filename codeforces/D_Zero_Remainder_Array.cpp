#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int value = ceil(arr[i] / (double)k) * k;
            if (value != arr[i]) mp[value - arr[i]]++;
        }

        int ans = 0, x = 0;
        while (!mp.empty()) {
            auto it = mp.lower_bound(x);
            if (it == mp.end()) {
                ans += (k - x);
                x = 0;
            } else {
                int increment = (*it).first - x;

                ans += (increment + 1);
                x = (x + increment + 1) % k;

                mp[(*it).first]--;
                if (mp[(*it).first] == 0) mp.erase((*it).first);
            }
        }

        cout << ans << endl;
    }
}