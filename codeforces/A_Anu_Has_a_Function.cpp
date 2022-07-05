#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    vector<int> prefix(n), suffix(n);
    for (int i = 1; i < n; i++) {
        if (i == 1)
            prefix[1] = ~arr[0];
        else
            prefix[i] = prefix[i - 1] & (~arr[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        if (i == n - 2)
            suffix[i] = ~arr[n - 1];
        else
            suffix[i] = suffix[i + 1] & (~arr[i + 1]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        int check_value;
        if (i == 0) {
            check_value = arr[i] & suffix[i];
        } else if (i == n - 1) {
            check_value = arr[i] & prefix[i];
        } else {
            check_value = arr[i] & prefix[i] & suffix[i];
        }

        int current_value;
        if (index == 0) {
            current_value = arr[index] & suffix[index];
        } else if (index == n - 1) {
            current_value = arr[index] & prefix[index];
        } else {
            current_value = arr[index] & prefix[index] & suffix[index];
        }

        if (check_value > current_value) index = i;
    }

    cout << arr[index] <<" ";
    for (int i = 0; i < n; i++)
        if (i != index) cout << arr[i] << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}