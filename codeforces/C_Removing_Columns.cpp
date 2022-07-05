#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> check_indices;
    for (int i = 0; i < n - 1; i++) check_indices.insert(i);

    int ans = 0;
    for (int j = 0; j < m && check_indices.size() > 0; j++) {
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] > arr[i + 1][j] && check_indices.count(i)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            ans++;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (arr[i][j] < arr[i + 1][j] && check_indices.count(i)) {
                    check_indices.erase(i);
                }
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}