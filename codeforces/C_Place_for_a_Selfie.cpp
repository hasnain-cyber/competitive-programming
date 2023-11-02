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
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a * c <= 0) {
            cout << "NO" << endl;
        }
        else {
            double root = sqrt(4 * a * c);
            double idx = upper_bound(arr.begin(), arr.end(), b - root) - arr.begin();

            if (idx == n || arr[idx] >= b + root) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
                cout << arr[idx] << endl;
            }
        }
    }

    cout << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}