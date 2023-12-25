#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

// #define int long long int
// #define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i].first;
        arr[i].first--;
    }
    for (int i = 0; i < k; i++) {
        cin >> arr[i].second;
        arr[i].second--;
    }

    int q;
    cin >> q;
    vector<int> count(n, 0);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        count[x - 1]++;
    }

    string ans;
    for (int i = 0; i < k; i++) {
        string temp = s.substr(arr[i].first, arr[i].second - arr[i].first + 1);
        int l = arr[i].first, r = arr[i].second;
        int sum = 0;
        for (int j = l; j <= (l + r) / 2; j++) {
            sum += count[j] + count[l + r - j];
            if (sum & 1) swap(temp[j - l], temp[r - j]);
        }
        ans.append(temp);
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}