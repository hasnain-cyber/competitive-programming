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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s1 += a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
        s2 += b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (k == 1) {
        if (a[0] < b[m - 1]) {
            swap(a[0], b[m - 1]);
            s1 += b[m - 1] - a[0];
            s2 += a[0] - b[m - 1];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }
        cout << s1 << endl;
    }
    else if (k == 2) {
        if (a[0] < b[m - 1]) {
            swap(a[0], b[m - 1]);
            s1 += b[m - 1] - a[0];
            s2 += a[0] - b[m - 1];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }

        if (a[n - 1] > b[0]) {
            swap(a[n - 1], b[0]);
            s1 += b[0] - a[n - 1];
            s2 += a[n - 1] - b[0];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }

        cout << s1 << endl;
    }
    else {
        if (a[0] < b[m - 1]) {
            swap(a[0], b[m - 1]);
            s1 += b[m - 1] - a[0];
            s2 += a[0] - b[m - 1];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }

        if (a[n - 1] > b[0]) {
            swap(a[n - 1], b[0]);
            s1 += b[0] - a[n - 1];
            s2 += a[n - 1] - b[0];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }
        
        if (k & 1) {
            swap(a[0], b[m - 1]);
            s1 += b[m - 1] - a[0];
            s2 += a[0] - b[m - 1];
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
        }

        cout << max(s1, s2) << endl;
    }
    
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}