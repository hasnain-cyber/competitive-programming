#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define loop(n) for (int i = 0; i < n; i++)
#define vi vector<int>

#define endl '\n'

using namespace std;

vector<pair<int, int>> get_reduced(const vi &arr, int n, int m) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int value = arr[i];
        while (value % m == 0) value /= m;

        if (ans.size() > 0 && ans.back().first == value) {
            ans.back().second += arr[i] / value;
        } else {
            ans.push_back({value, arr[i] / value});
        }
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    loop(t) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        loop(n) cin >> a[i];

        int k;
        cin >> k;
        vi b(k);
        loop(k) cin >> b[i];

        vector<pair<int, int>> c = get_reduced(a, n, m);
        vector<pair<int, int>> d = get_reduced(b, k, m);

        if (c == d)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}