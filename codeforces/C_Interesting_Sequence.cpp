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

// find min number greater than n, such that its ith bit is off.
int binary_search(int n, int i) {
    int k = n;
    while(true) {
        int bit = (k >> i) & 1;
        if (!bit) {
            return k;
        }
        k++;
    }
}

void solve_testcase() {
    int n, x;
    cin >> n >> x;

    int m_max = n;
    for (int i = 0; i < 32; i++) {
        int bit = (n >> i) & 1;

        // if bit is off, find the min m, such that the bit is off
        if (!bit) {
            int m = binary_search(n, i);
            cout << i << " " << m << endl;
            m_max = max(m_max, m);
        }
    }

    int value = n;
    for (int i = n + 1; i <= m_max; i++) {
        value = value ^ i;
    }

    if (value == x) {
        cout << m_max << endl;
    } else {
        cout << -1 << endl;
    }
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