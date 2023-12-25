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
    string s;
    cin >> s;
    int n = s.size();

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') counter++;
        else counter--;

        if (counter < 0) {
            break;
        }
    }

    if (counter >= 0) {
        cout << "1 1" << endl;
        return;
    }

    // swap first - and last +
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            idx1 = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '+') {
            idx2 = i;
            break;
        }
    }

    if (idx1 == -1 || idx2 == -1) {
        cout << -1 << endl;
        return;
    }

    swap(s[idx1], s[idx2]);
    // cout << s << endl;

    counter = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') counter++;
        else counter--;

        if (counter < 0) {
            break;
        }
    }

    if (counter >= 0) {
        cout << idx1 + 1 << " " << idx2 + 1 << endl;
        return;
    }

    cout << -1 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}