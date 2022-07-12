#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int solve_testcase(vector<int> &arr, int check_value) {
    int n = arr.size();

    int ans = 0;
    for (int x = 0; x < pow(2, n); x++) {
        int s = 0;

        // check each bit in x and if it is set, add the corresponding element to sum;
        for (int k = 0; k < n; k++) {
            if ((x >> k) & 1) {
                s += arr[k];
            }
        }

        if (s >= check_value) {
            ans++;
        }
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << solve_testcase(arr, 1) << endl;
}