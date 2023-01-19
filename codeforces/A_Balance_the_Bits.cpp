#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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
    string s;
    cin >> s;

    if (s[0] == '0' || s[n - 1] == '0') {
        cout << "NO" << endl;
        return;
    }

    int counter_zeros = 0;
    for (int i = 0; i < n; i++) {
        counter_zeros += (s[i] == '0' ? 1 : 0);
    }

    if (counter_zeros % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    int counter_ones = n - counter_zeros;

    string ans_1, ans_2;
    int flipper = 0, counter_open = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (flipper == 0) {
                ans_1.push_back('(');
                ans_2.push_back(')');
            } else {
                ans_1.push_back(')');
                ans_2.push_back('(');
            }
            flipper = 1 - flipper;
        } else {
            if (counter_open >= counter_ones / 2) {
                ans_1.push_back(')');
                ans_2.push_back(')');
            } else {
                ans_1.push_back('(');
                ans_2.push_back('(');
                counter_open++;
            }
        }
    }

    cout << "YES" << endl;
    cout << ans_1 << endl;
    cout << ans_2 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}