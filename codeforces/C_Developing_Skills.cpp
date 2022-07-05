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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            ans += arr[i] / 10;
            pq.push({arr[i] % 10, arr[i]});
        }

        while (k > 0 && !pq.empty()) {
            pair<int, int> element = pq.top();
            pq.pop();

            if (element.second >= 100) continue;

            int cost = 10 - element.first;
            if (cost <= k) {
                ans++;
                k -= cost;
                pq.push({0, element.second + cost});
            } else
                k = 0;
        }

        cout << ans << endl;
    }
}