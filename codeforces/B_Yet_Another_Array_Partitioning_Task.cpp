#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<pair<int, int>> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort_arr(arr);

    set<int> s;
    int sum = 0;
    for (int i = 0; i < m * k; i++) {
        pair<int, int> element = arr[n - i - 1];
        sum += element.first;
        s.insert(element.second);
    }

    cout << sum << endl;
    int counter = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s.count(i)) {
            counter++;
        }

        if (counter == m) {
            ans.push_back(i + 1);
            counter = 0;
        }
    }
    ans.pop_back();
    print_arr(ans);
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