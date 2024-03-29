#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T>& arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;

    vector<int> freq(26, 0);
    for (int i = 0; i < n;i++) {
        if (i >= k || i + k < n) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        else {
            if (s[i] != t[i]) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < 26;i++) {
        if (freq[i] != 0) {
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
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}