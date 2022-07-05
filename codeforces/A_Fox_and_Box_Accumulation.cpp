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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                pq.push(1);
            else {
                if (!pq.empty() && pq.top() <= a[i]) {
                    int element = pq.top();
                    pq.pop();
                    element++;
                    pq.push(element);
                } else {
                    pq.push(1);
                }
            }
        }

        cout << pq.size() << endl;
    }
}