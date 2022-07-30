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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, h = n;
    while (l <= h) {
        int mid = (l + h) / 2;

        int curr_q = q;
        for (int i = mid; i < n; i++) {
            if (arr[i] > curr_q) {
                curr_q--;
            }
        }

        if (curr_q < 0) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    string ans;
    for (int i = 0; i < l; i++) {
        if (arr[i] <= q) {
            ans.push_back('1');
        } else {
            ans.push_back('0');
        }
    }

    for (int i = l; i < n; i++) {
        ans.push_back('1');
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