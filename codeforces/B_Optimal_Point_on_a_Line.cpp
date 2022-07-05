#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int find_distance(const vector<pair<int, int>> &arr, int x, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(arr[i].first - arr[x].first);
    }

    cout << arr[x].first << " " << ans << endl;

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    cout << arr[(n - 1) / 2] << endl;
}