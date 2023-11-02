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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int count_odds = 0;
    for(int i = 0; i < 26; i++) {
        if (freq[i]&1) {
            count_odds++;
        }
    }

    if (count_odds > k + 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}