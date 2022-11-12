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

    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
        return;
    } else {
        for (int i = 0; i < n; i++) {
            if (arr[i] & 1) {
                arr[i] += arr[i] % 10;
            }
        }
    }

    sort_arr(arr);
    for (int i = 0; i < n - 1; i++) {
        int last = arr[i] % 10;
        int difference = (arr[i + 1] - arr[i]) % 20;
        if (difference == 0) continue;

        if (last == 2) {
            if (difference == 2 || difference == 6 || difference == 14) {
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        } else if (last == 4) {
            if (difference == 4 || difference == 12 || difference == 18) {
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        } else if (last == 8) {
            if (difference == 8 || difference == 14 || difference == 16) {
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        } else {
            if (difference == 6 || difference == 8 || difference == 12) {
                continue;
            } else {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
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