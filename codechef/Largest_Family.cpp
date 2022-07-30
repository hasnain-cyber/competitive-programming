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
    sort_arr(arr);

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    int count_zeros = 0;
    for (int i = 0; i < n; i++) {
        int value = arr[i];

        if (value == 0) {
            count_zeros++;
        } else {
            if(pq.empty()) {
                pq.push(value);
            } else {
                int top_value = pq.top();
                pq.pop();

                pq.push(value);
                top_value--;
                if (top_value != 0) {
                    pq.push(top_value);
                } else {
                    ans++;
                }
            }
        }
    }

    ans += count_zeros;
    while (!pq.empty()) {
        int top_value = pq.top();
        pq.pop();
        if (count_zeros >= top_value) {
            count_zeros -= top_value;
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}