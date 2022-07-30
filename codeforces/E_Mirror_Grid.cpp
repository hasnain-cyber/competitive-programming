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
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost1 = ('1' - arr[i][j]);
            cost1 += ('1' - arr[j][n - 1 - i]);
            cost1 += ('1' - arr[n - 1 - i][n - 1 - j]);
            cost1 += ('1' - arr[n - 1 - j][i]);

            int cost2 = (arr[i][j] - '0');
            cost2 += (arr[j][n - 1 - i] - '0');
            cost2 += (arr[n - 1 - i][n - 1 - j] - '0');
            cost2 += (arr[n - 1 - j][i] - '0');

            if (cost1 < cost2) {
                arr[i][j] = '1';
                arr[j][n - 1 - i] = '1';
                arr[n - 1 - i][n - 1 - j] = '1';
                arr[n - 1 - j][i] = '1';

                ans += cost1;
            } else {
                arr[i][j] = '0';
                arr[j][n - 1 - i] = '0';
                arr[n - 1 - i][n - 1 - j] = '0';
                arr[n - 1 - j][i] = '0';

                ans += cost2;
            }
        }
    }

    cout << ans << endl;
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