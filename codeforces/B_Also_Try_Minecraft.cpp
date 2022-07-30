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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // preprocess
    vector<int> prefix1(n);
    prefix1[0] = 0;
    for (int i = 1; i < n; i++) {
        prefix1[i] = prefix1[i - 1] + max((int)0, arr[i - 1] - arr[i]);
    }

    vector<int> prefix2(n);
    prefix2[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        prefix2[i] = prefix2[i + 1] + max((int)0, arr[i + 1] - arr[i]);
    }

    while (m--) {
        int i, j;
        cin >> i >> j;
        i--, j--;

        if (i <= j) {
            cout << prefix1[j] - prefix1[i] << endl;
        } else {
            cout << prefix2[j] - prefix2[i] << endl;
        }
    }
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