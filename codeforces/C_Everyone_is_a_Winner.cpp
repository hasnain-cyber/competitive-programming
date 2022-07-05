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
        int n;
        cin >> n;

        set<int> ans = {0, 1};
        for (int k = 1; k <= sqrt(n); k++) {
            int value1 = n / (n / k);
            int value2 = n / k;
            ans.insert(value1);
            ans.insert(value2);
        }

        cout << ans.size() << endl;
        for (int element : ans) cout << element << " ";
        cout << endl;
    }
}