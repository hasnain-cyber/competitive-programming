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
        for (int i = 0; i < n; i++) mp[arr[i]]++;

        if (mp.size() > k)
            cout << -1 << endl;
        else {
            vector<int> temp;
            for (auto it : mp) temp.push_back(it.first);
            while(temp.size() < k) temp.push_back(1);

            vector<int> ans;
            for (int i = 0; i < n; i++) {
                for (auto element : temp) ans.push_back(element);
            }

            cout << ans.size() << endl;
            for (auto element : ans) cout << element << " ";
            cout << endl;
        }
    }
}