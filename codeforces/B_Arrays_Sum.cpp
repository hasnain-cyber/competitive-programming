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
        for (int element : arr) mp[element]++;

        if (mp.size() == 1) {
            if (k >= 1)
                cout << 1 << endl;
            else
                cout << -1 << endl;
        } else if (k == 1) {
            cout << -1 << endl;
        }
        else if (k >= mp.size()) {
            cout << 1 << endl;
        } else {
            cout << ceil((mp.size() - k) / (double)(k - 1)) + 1 << endl;
        }
    }
}