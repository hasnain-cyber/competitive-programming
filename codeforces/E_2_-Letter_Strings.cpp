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
    vector<vector<int>> count(26, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;

        count[(int)(value[0] - 'a')][(int)(value[1] - 'a')]++;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int first = count[i][j];

            for (int k = 0; k < 26; k++) {
                if (k == i) continue;

                // second char same
                ans += first * (count[k][j]);
            }

            for (int k = 0; k < 26; k++) {
                if (k == j) continue;

                // second char same
                ans += first * (count[i][k]);
            }
        }
    }

    cout << ans / 2 << endl;
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