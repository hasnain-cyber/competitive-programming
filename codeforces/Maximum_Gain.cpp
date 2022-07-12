#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            s += b[i];
        }
        int k;
        cin >> k;

        int ans = 0;
        for (int l1 = 0; l1 <= k; l1++) {
            // take n - k elements from between and have their min sum;
            int temp_length1 = n - l1;
            if (temp_length1 < 0) continue;

            int current1 = 0, s1 = 0;
            for (int i = 0; i < temp_length1; i++) {
                current1 += a[i];
            }
            s1 = current1;
            for (int i = 0; i + temp_length1 < n; i++) {
                current1 -= a[i];
                current1 += a[i + temp_length1];

                s1 = min(s1, current1);
            }

            int l2 = k - l1;
            int temp_length2 = m - l2;
            if (temp_length2 < 0) continue;

            int current2 = 0, s2 = 0;
            for (int i = 0; i < temp_length2; i++) {
                current2 += b[i];
            }
            s2 = current2;
            for (int i = 0; i + temp_length2 < m; i++) {
                current2 -= b[i];
                current2 += b[i + temp_length2];

                s2 = min(s2, current2);
            }

            ans = max(ans, s - s1 - s2);
        }

        cout << "Case #" << test_case << ": " << ans << endl;
    }
}