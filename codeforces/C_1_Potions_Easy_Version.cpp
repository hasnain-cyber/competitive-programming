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

    int s = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0 || (s + arr[i] >= 0)) {
            ans++;
            pq.push(arr[i]);
            s += arr[i];
        }
        else {
            if (pq.empty() || pq.top() >= arr[i]) continue;
            else {
                int value = pq.top();
                pq.pop();
                pq.push(arr[i]);
                s += (arr[i] - value);
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}