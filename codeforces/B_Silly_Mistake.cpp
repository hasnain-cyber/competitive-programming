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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<int> ans;
        bool flag = true;
        set<int> current, occurred;
        int current_length = 0;
        for (int i = 0; i < n && flag; i++) {
            if (arr[i] > 0) {
                if (current.count(arr[i]) || occurred.count(arr[i]))
                    flag = false;
                else {
                    current.insert(arr[i]);
                    occurred.insert(arr[i]);
                }
            } else {
                if (current.count(-arr[i]))
                    current.erase(-arr[i]);
                else
                    flag = false;
            }

            current_length += 1;
            if (current.empty()) {
                ans.push_back(current_length);
                current_length = 0;
                current.clear();
                occurred.clear();
            }
        }

        if (flag && current.empty()) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        } else
            cout << -1 << endl;
    }
}