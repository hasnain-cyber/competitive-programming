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
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    if (total < s) {
        cout << -1 << endl;
        return;
    } else if (total == s) {
        cout << 0 << endl;
        return;
    }

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int longest = -infinity;
    for (int i = 0; i < n; i++) {
        int required_sum = prefix[i] + s;

        int l = i, h = n;
        int index = -1;
        while (l <= h) {
            int mid = (l + h) / 2;

            if (prefix[mid] > required_sum) {
                h = mid - 1;
            } else if (prefix[mid] < required_sum) {
                l = mid + 1;
            } else {
                l = mid + 1;
                index = mid;
            }
        }

        if (index != -1) {
            longest = max(longest, index - i);
        }
    }

    if (longest == -infinity) {
        cout << -1 << endl;
    } else {
        cout << n - longest << endl;
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