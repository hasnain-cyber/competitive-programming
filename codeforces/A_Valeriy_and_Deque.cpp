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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int max_index = max_element(arr.begin(), arr.end()) - arr.begin();
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(arr[i]);
    }

    map<int, pair<int, int>> mp;
    for (int i = 0; i < max_index; i++) {
        int element1 = dq.front();
        dq.pop_front();
        int element2 = dq.front();
        dq.pop_front();

        mp[i] = {element1, element2};

        if (element1 < element2) {
            dq.push_front(element2);
            dq.push_back(element1);
        } else {
            dq.push_front(element1);
            dq.push_back(element2);
        }
    }

    vector<int> query_arr;
    dq.pop_front();
    while (!dq.empty()) {
        int ele = dq.front();
        dq.pop_front();
        query_arr.push_back(ele);
    }

    while (q--) {
        int query;
        cin >> query;

        if (query < max_index + 1) {
            cout << mp[query - 1].first << " " << mp[query - 1].second << endl;
        } else {
            query -= (max_index + 1);
            query %= (n - 1);

            cout << arr[max_index] << " " << query_arr[query] << endl;
        }
    }

    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
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