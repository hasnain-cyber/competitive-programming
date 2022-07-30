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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    for (int ele : arr) {
        mp[ele]++;
    }

    vector<int> reduced_arr;
    for (auto it : mp) {
        if (it.second >= k) {
            reduced_arr.push_back(it.first);
        }
    }

    if (reduced_arr.size() == 0) {
        cout << -1 << endl;
        return;
    }

    int start = 0, end = 0, ans_start = 0, ans_end = 0;
    for (int i = 1; i < reduced_arr.size(); i++) {
        int element = reduced_arr[i];

        if (element == reduced_arr[end] + 1) {
            end = i;
        } else {
            start = i;
            end = i;
        }

        if (end - start > ans_end - ans_start) {
            ans_start = start;
            ans_end = end;
        }
    }

    cout << reduced_arr[ans_start] << " " << reduced_arr[ans_end] << endl;
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