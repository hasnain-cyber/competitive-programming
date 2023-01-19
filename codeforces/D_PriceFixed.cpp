#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

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
    vector<pii> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort_arr(arr);

    deque<pii> dq;
    int total_products = 0;
    for (int i = 0; i < n; i++) {
        dq.push_back(arr[i]);
        total_products += arr[i].first;
    }

    int ans = 0, bought = 0;
    while (!dq.empty()) {
        if (bought >= dq.front().first) {
            bought += dq.front().second;
            ans += dq.front().second;
            dq.pop_front();
            continue;
        }

        // if can't buy from front, buy from back
        // first, calculate more items needed to be bought to get a discount
        int more_items = dq.front().first - bought;
        if (more_items <= dq.back().second) {
            bought += more_items;
            ans += 2* more_items;
            dq.back().second -= more_items;
            if (dq.back().second == 0) {
                dq.pop_back();
            }
        } else {
            bought += dq.back().second;
            ans += 2 * dq.back().second;
            dq.pop_back();
        }
    }

    cout << ans << endl;
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