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
    int n;
    cin >> n;
    vector<int> strength(n), endurance(n);
    for (int i = 0; i < n; i++) {
        cin >> strength[i];
        cin >> endurance[i];
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (strength[i] >= strength[0] && endurance[i] >= endurance[0]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << strength[0] << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}