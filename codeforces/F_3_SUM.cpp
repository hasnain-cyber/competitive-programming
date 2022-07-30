#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i] % 10]++;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                if (i == j && mp[i] < 2) {
                    continue;
                } else if (j == k && mp[j] < 2) {
                    continue;
                } else if (k == i && mp[k] < 2) {
                    continue;
                } else if (i == j && j == k && mp[i] < 3) {
                    continue;
                }

                int value = (i + j + k) % 10;
                if (value == 3) {
                    ans += (mp[i] * mp[j] * mp[k]);
                }
            }
        }
    }

    if (ans > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}