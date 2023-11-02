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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> counts(n);
    counts[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            int value = 1;
            while (arr[i] * value < arr[i - 1]) {
                counts[i]++;
                value *= 2;
            }
        }
        else {
            int value = arr[i];
            while (value / 2 >= arr[i - 1]) {
                counts[i]--;
                value /= 2;
            }
        }
    }

    int ans = 0, curr = 0;
    for (int i = 1; i < n; i++) {
        curr = max((int)0, curr + counts[i]);
        ans += curr;
    }
    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}