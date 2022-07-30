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
        cout << "YES" << endl;
        return;
    } else {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                flag = true;
                break;
            }
        }

        if (flag) {
            bool flag = false;
            sort_arr(arr);
            for (int i = 0; i < n - 1; i++) {
                if (arr[i] + 1 == arr[i + 1]) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                cout << "NO" << endl;
                return;
            } else {
                cout << "YES" << endl;
                return;
            }
        } else {
            cout << "YES" << endl;
            return;
        }
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