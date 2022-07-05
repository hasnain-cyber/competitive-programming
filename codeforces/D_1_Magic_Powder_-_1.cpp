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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({b[i] / a[i], i});
            b[i] = b[i] % a[i];
        }

        while (k > 0) {
            pair<int, int> element = pq.top();
            pq.pop();

            int i = element.second;
            int cost = a[i] - b[i];
            b[i] = 0;

            if (cost <= k) {
                k -= cost;
                pq.push({element.first + 1, i});
            } else {
                pq.push(element);
                break;
            }
        }

        cout << pq.top().first << endl;
    }
}