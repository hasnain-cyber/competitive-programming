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
    int n, k;
    cin >> n >> k;
    vector<int> freq(11, 0);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        freq[value]++;
        arr[i] = value;
    }

    if (k == 2) {
        if (freq[2] >= 1 || freq[4] >= 1 || freq[6] >= 1 || freq[8] >= 1 || freq[10] >= 1) {
            cout << 0 << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    else if (k == 3) {
        if (freq[3] >= 1 || freq[6] >= 1 || freq[9] >= 1) {
            cout << 0 << endl;
        }
        else if (freq[2] >= 1 || freq[5] >= 1 || freq[8] >= 1) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    else if (k == 4) {
        int factors_2 = freq[2] + 2 * freq[4] + freq[6] + 3 * freq[8] + freq[10];
        if (factors_2 >= 2) {
            cout << 0 << endl;
        }
        else if (factors_2 == 1) {
            if (n == 1) {
                // just one element, take it to nearest multiple of 4
                int operations = (arr[0] / (double)4) * 4 - arr[0];
                cout << operations << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else {
            if (n == 1) {
                int operations = (arr[0] / (double)4) * 4 - arr[0];
                cout << operations << endl;
            }
            else if (freq[3] >= 1 || freq[7] >= 1) {
                cout << 1 << endl;
            }
            else {
                cout << 2 << endl;
            }
        }
    }
    else {
        // for k = 5
        if (freq[5] >= 1 || freq[10] >= 1) {
            cout << 0 << endl;
        }
        else if (freq[4] >= 1 || freq[9] >= 1) {
            cout << 1 << endl;
        } else if (freq[3] >= 1 || freq[8] >= 1) {
            cout << 2 << endl;
        } else if (freq[2] >= 1 || freq[7] >= 1) {
            cout << 3 << endl;
        } else {
            cout << 4 << endl;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}