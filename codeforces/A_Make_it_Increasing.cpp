#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = infinity;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        int temp = 0;
        for (int j = i - 1; j >= 0; j--) {
            temp = temp + arr[j] - temp % arr[j];
            curr += temp / arr[j];
        }

        temp = 0;
        for (int j = i + 1; j < n; j++) {
            temp = temp + arr[j] - temp % arr[j];
            curr += temp / arr[j];
        }

        ans = min(ans, curr);
    }

    cout << ans << endl;
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