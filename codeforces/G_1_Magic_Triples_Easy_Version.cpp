#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

const int N = 1e6 + 1;
int mp[N];

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < N; i++) mp[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (mp[arr[i]] - 1) * ((long long)1) * (mp[arr[i]] - 2);
        for (int k = 2; arr[i] * k * k <= N; k++) {
            ans += mp[arr[i] * k] * ((long long)1) * mp[arr[i] * k * k];
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}