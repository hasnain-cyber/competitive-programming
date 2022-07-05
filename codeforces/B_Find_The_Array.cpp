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

        int sum_odd = 0, sum_even = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1)
                sum_odd += arr[i];
            else
                sum_even += arr[i];
        }

        vector<int> ans = arr;
        if (sum_even >= sum_odd)
            for (int i = 1; i < n; i += 2) ans[i] = 1;
        else
            for (int i = 0; i < n; i += 2) ans[i] = 1;

        for (int element : ans) cout << element << " ";
        cout << endl;
    }
}