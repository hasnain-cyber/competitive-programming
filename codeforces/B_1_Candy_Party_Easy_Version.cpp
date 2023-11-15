#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];

    if (s % n) {
        cout << "NO" << endl;
        return;
    }
    int avg = s / n;

    int counter = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(arr[i] - avg);
        if (diff == 0) counter++;
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int diff = arr[i] - avg;
        if (diff == 0) continue;
        if (__builtin_popcount(abs(diff)) != 1) {
            cout << "NO" << endl;
            return;
        }

        if (diff > 0) {
            if (arr[i] < diff * 2) {
                cout << "NO" << endl;
                return;
            }
            else {
                mp[diff]++;
                if (mp[diff] == 0) mp.erase(diff);
                if (counter == 0) {
                    cout << "NO" << endl;
                    return;
                }
                else {
                    counter--;
                }
            }
        }
        else {
            mp[-diff]--;
            if (mp[-diff] == 0) mp.erase(-diff);
            if (arr[i] >= -diff * 2) counter++;
        }
    }

    if (mp.size() > 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}