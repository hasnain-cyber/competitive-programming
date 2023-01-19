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

void solve_testcase() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> count_arr(x + 1, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] <= x) {
            count_arr[arr[i]]++;
        }
    }

    for (int i = 1; i < x; i++) {
        int div = count_arr[i] / (i + 1);
        int rem = count_arr[i] % (i + 1);
        count_arr[i + 1] += div;
        count_arr[i] = rem;
    }

    for (int i = 1; i < x; i++) {
        if (count_arr[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}