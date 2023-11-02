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
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    int ans = 0, counter = 0;
    while (i < j) {
        if (arr[j] <= counter) {
            j--;
            ans++;
            counter = 0;
        }
        else {
            int rem = arr[j] - counter;
            if (arr[i] <= rem) {
                counter += arr[i];
                ans += arr[i];
                i++;
            }
            else {
                counter += rem;
                ans += rem;
                arr[i] -= rem;
            }
        }
    }

    // cout << "i: " << i << ", j: " << j << ", counter: " << counter << endl;
    if (i == j) {
        if (arr[i] <= counter) {
            ans++;
        }
        else {
            if (arr[i] == 1) {
                ans++;
            }
            else {
                ans += (arr[i] - counter + 1) / 2 + 1;
            }
        }
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