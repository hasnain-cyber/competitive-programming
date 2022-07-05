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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                int j = i;
                while (j < n && arr[j] != 0) j++;

                i = j;
                ans++;
            }
        }

        cout << min(ans, (int)2) << endl;
    }
}