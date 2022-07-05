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
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > 0) pq.push({arr[i], i});
        }

        vector<pair<int, int>> ans;
        while (pq.size() > 1) {
            auto element1 = pq.top();
            pq.pop();
            auto element2 = pq.top();
            pq.pop();

            element1.first--;
            element2.first--;
            ans.push_back({element1.second + 1, element2.second + 1});

            if (element1.first > 0) pq.push(element1);
            if (element2.first > 0) pq.push(element2);
        }

        cout << ans.size() << endl;
        for (pair<int, int> element : ans) cout << element.first << " " << element.second << endl;
    }
}