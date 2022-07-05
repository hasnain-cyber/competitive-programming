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

        vector<int> indices;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] < arr[i + 1] * 2) indices.push_back(i);
        }

        int ans = 0;
        for (int i = k - 1; i < indices.size(); i++) {
            if (indices[i] == indices[i - k + 1] + k - 1) ans++;
        }

        cout << ans << endl;
    }
}