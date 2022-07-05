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
    t = 1;
    while (t--) {
        int n;
        cin >> n;

        map<int, int> mp;
        while (n > 0) {
            int k = log10(n);
            int value = pow(10, k);
            mp[value]++;
            n -= value;
        }

        int size = MIN;
        for (auto it : mp) size = max(size, it.second);

        vector<int> ans(size, 0);
        for (auto it : mp) {
            for (int i = 0; i < it.second; i++) ans[i] += it.first;
        }

        cout << size << endl;
        for (int i = 0; i < size; i++) cout << ans[i] << " ";
    }
}