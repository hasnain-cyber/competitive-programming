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
    int a, b;
    cin >> a >> b;
    int min_steps = b - a;

    for (int k1 = 0; k1 <= b - a; k1++) {
        int steps = 1 + k1 - b;
        int a1 = a + k1;
        int b1 = 0;
        for (int i = 31; i >= 0; i--) {
            int a_bit = a1 & (1 << i);
            int b_bit = b & (1 << i);

            if (b_bit) {
                b1 |= (1 << i);
            } else {
                if(a_bit) {
                    b1 |= (1 << i);
                    break;
                }
            }
        }

        steps += a1 | b1;
        min_steps = min(min_steps, steps);
    }

    cout << min_steps << endl;
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