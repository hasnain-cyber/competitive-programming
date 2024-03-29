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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    m--;

    priority_queue<int> pq1;
    int ans = 0;
    int curr_sum = 0;
    for (int i = m; i > 0; i--) {
        pq1.push(arr[i]);
        curr_sum += arr[i];
        if (curr_sum > 0) {
            curr_sum -= 2 * pq1.top();
            ans++;
            pq1.pop();
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq2;
    curr_sum = 0;
    for (int i = m + 1; i < n; i++) {
        pq2.push(arr[i]);
        curr_sum += arr[i];
        if (curr_sum < 0) {
            curr_sum += 2 * (-pq2.top());
            ans++;
            pq2.pop();
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