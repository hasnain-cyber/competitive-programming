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

int find(int n, int pos) {
    int low = 1, high = n, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int removed_length = (mid - 1) * n - ((mid - 2) * (mid - 1)) / 2;
        if (removed_length < pos) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

void solve_testcase() {
    string s;
    cin >> s;
    int n = s.size();
    int pos;
    cin >> pos;

    // find the string in which the pos-th character occurs
    int k = find(n, pos);

    // find the order in which the characters will be removed
    vector<int> order;
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && s[stk.top()] > s[i]) {
            order.push_back(stk.top());
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty()) {
        order.push_back(stk.top());
        stk.pop();
    }

    set<int> removed;
    for (int i = 0; i < k - 1; i++) {
        removed.insert(order[i]);
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (removed.find(i) == removed.end()) ans.push_back(s[i]);
    }

    int removed_length = (k - 1) * n - ((k - 2) * (k - 1)) / 2;
    cout << ans[pos - removed_length - 1];
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}