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
    int n, h, m;
    cin >> n >> h >> m;
    vector<pair<int, int>> arr(n);
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first > h || (arr[i].first == h && arr[i].second >= m)) {
            flag = true;
        }
    }

    sort_arr(arr);
    int ans = 0;
    if (flag){
        for (int i = 0; i < n; i++) {
            if (arr[i].first > h || (arr[i].first == h && arr[i].second >= m)) {
                ans = (arr[i].first - h) * 60 + (arr[i].second - m);
                break;
            }
        }
    } else {
        ans += (24 - h) * 60 - m;
        ans += arr[0].first * 60 + arr[0].second;
    }

    cout << ans / 60 << " " << ans % 60 << endl;
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