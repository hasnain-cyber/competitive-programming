#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == '1') {
            if (j < i + 1) j = i + 1;
            while (j < n && arr[j] == '1') {
                j++;
            }

            if (j < n) {
                if (j - i <= k) {
                    k -= (j - i);
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    cout << arr << endl;
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