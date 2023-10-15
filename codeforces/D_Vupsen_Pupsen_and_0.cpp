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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i += 2) {
        if (i + 3 == n) {
            if (arr[i] != arr[i + 1]) {
                ans[i] = -arr[i + 2];
                ans[i + 1] = arr[i + 2];
                ans[i + 2] = (arr[i] - arr[i + 1]);
            }
            else if (arr[i + 1] != arr[i + 2]) {
                ans[i] = (arr[i + 1] - arr[i + 2]);
                ans[i + 1] = -arr[i];
                ans[i + 2] = arr[i];
            }
            else {
                ans[i] = -arr[i];
                ans[i + 1] = -arr[i];
                ans[i + 2] = 2 * arr[i];
            }
            i++;
        }
        else {
            ans[i] = -arr[i + 1];
            ans[i + 1] = arr[i];
        }
    }

    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}