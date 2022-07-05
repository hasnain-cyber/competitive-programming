#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int find_base_value(int n, int k) {
    if (k == 1) return n;

    while (n % k == 0) n /= k;

    return n;
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int base_value = find_base_value(arr[i], k);
        mp[base_value].push_back(arr[i] / base_value);
    }

    int ans = 0;
    for (auto it : mp) {
        sort(it.second.begin(), it.second.end());

        int length = it.second.size();
        for (int i = 0; i < length; i++) {
            ans++;
            if (i != length - 1 && it.second[i + 1] == it.second[i] * k)
                i++;
        }
    }

    cout << ans << endl;
}