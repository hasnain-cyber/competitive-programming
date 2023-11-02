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

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string s;
    cin >> s;

    int xor_zero = 0, xor_one = 0;
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') xor_zero ^= arr[i];
        else xor_one ^= arr[i];

        pre[i] = (i > 0 ? pre[i - 1] : 0) ^ arr[i];
    }

    int q;
    cin >> q;
    vector<int> ans;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            xor_zero ^= (pre[r] ^ (l > 0 ? pre[l - 1] : 0));
            xor_one ^= (pre[r] ^ (l > 0 ? pre[l - 1] : 0));
        }
        else {
            int query_type;
            cin >> query_type;
            ans.push_back(query_type ? xor_one : xor_zero);
        }
    }

    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}