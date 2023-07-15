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
    string s;
    cin >> s;

    if (n & 1) {
        cout << -1 << endl;
        return;
    }

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
        if (freq[c] > n / 2) {
            cout << -1 << endl;
            return;
        }
    }

    map<char, int> matching_freq;
    int max_matching_pairs = 0, total_matching_pairs = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) {
            matching_freq[s[i]]++;
            total_matching_pairs++;
            max_matching_pairs = max(max_matching_pairs, matching_freq[s[i]]);
        }
    }

    cout << max(max_matching_pairs, (int)ceil(total_matching_pairs / 2.0)) << endl;
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