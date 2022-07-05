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
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int , int>>, greater<pair<int, int>>> sum_values;
        for (int i = 1; i <= m; i++) sum_values.push({0, i});

        for (int i = 0; i < n; i++) {
            pair<int, int> it = sum_values.top();
            sum_values.pop();

            ans[i] = it.second;
            pair<int, int> push_element = {it.first + arr[i], it.second};
            sum_values.push(push_element);
        }

        cout << "YES" << endl;
        for (auto element : ans) cout << element << " ";
        cout << endl;
    }
}