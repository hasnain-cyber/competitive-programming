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

    if (n == 1) {
        if (arr[0] == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    bool flag = true;
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            if (arr[i] == 0) {
                bool check_flag = true;
                for (int i = 1; i < n; i++) {
                    if (arr[i] != 0) {
                        check_flag = false;
                        break;
                    }
                }
                flag = check_flag;
            } else if (ans[i] < arr[i]) {
                int inc = arr[i] - ans[i];
                ans[i + 1] = -(inc - 1);
                ans[i] += inc;
            } else {
                flag = false;
                break;
            }
        } else {
            if (arr[i] == ans[i]) {
                continue;
            } else if (ans[i] < arr[i]) {
                int inc = arr[i] - ans[i];
                ans[i + 1] = -(inc - 1);
                ans[i] += inc;
            } else {
                flag = false;
                break;
            }
        }
    }

    if (ans[n - 1] != arr[n - 1] + 1) {
        flag = false;
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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