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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int& element : arr)
        cin >> element;

    vector<int> powers(m);
    for (int i = 0; i < m; i++)
        cin >> powers[i];

    int highest_power = infinity;
    for (int i = 0; i < m; i++) {
        if (powers[i] >= highest_power) continue;

        for (int j = 0;j < n; j++) {
            if (arr[j] % (1 << powers[i]) == 0)
            {
                arr[j] += (1 << (powers[i] - 1));
            }
        }

        highest_power = powers[i];
    }

    print_arr(arr);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}