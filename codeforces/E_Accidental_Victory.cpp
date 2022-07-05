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
        vector<pair<int, int>> arr(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            arr[i] = {value, i};
            s += value;
        }
        sort(arr.begin(), arr.end());

        vector<int> ans = {arr[n - 1].second + 1};
        int running_sum = arr[n - 1].first;
        for (int i = n - 2; i >= 0; i--) {
            int prefix_sum = s - running_sum;

            if (prefix_sum >= arr[i + 1].first) {
                running_sum += arr[i].first;
                ans.push_back(arr[i].second + 1);
            } else
                break;
        }

        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int element : ans) cout << element << " ";
        cout << endl;
    }
}