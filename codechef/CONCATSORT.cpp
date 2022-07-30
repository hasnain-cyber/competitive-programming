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
    vector<int> sorted_arr = arr;
    sort_arr(sorted_arr);

    int i = 0, j = 0;
    vector<int> p, q;
    while (i < n) {
        if (arr[i] == sorted_arr[j]) {
            p.push_back(arr[i]);
            i++, j++;
        } else {
            q.push_back(arr[i]);
            i++;
        }
    }

    for (int ele : q) {
        p.push_back(ele);
    }

    for (int i = 0; i < n - 1; i++) {
        if (p[i] > p[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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