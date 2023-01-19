#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
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

vector<int> factors;
void seive() {
    int n = 1e7 + 7;
    factors = vector<int>(n + 1, -1);

    for (int p = 2; p <= n; p++) {
        if (factors[p] == -1) {
            factors[p] = p;
            for (int i = p * p; i <= n; i += p) {
                if (factors[i] == -1) {
                    factors[i] = p;
                }
            }
        }
    }
}

void solve_testcase() {
    int x, y;
    cin >> x >> y;
    x = min(x, y);
    y = max(x, y);
    y -= x;

    // finding prime factors of y using seive
    int min_k = infinity;
    while(y > 1) {
        int p = factors[y];
        int k = ceil(x / (double)p) * p - x;
        min_k = min(min_k, k);
        while (y % p == 0) {
            y /= p;
        }
    }

    if (min_k == infinity) {
        cout << -1 << endl;
    } else {
        cout << min_k << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    seive();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}