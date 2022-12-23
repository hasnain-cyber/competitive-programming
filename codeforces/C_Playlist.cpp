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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        // take input as beauty and length
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int current_total_length = 0;
    int ans = -infinity;
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, arr[i].first * (arr[i].second + current_total_length));

        pq.push(arr[i].second);
        current_total_length += arr[i].second;
        if (pq.size() > k - 1) {
            current_total_length -= pq.top();
            pq.pop();
        }
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