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
    string s;
    cin >> s;
    int winning_rounds = 0;
    for (int i = 0; i < n; i++) {
        winning_rounds += s[i] - '0';
    }

    for (int i = (1 << winning_rounds); i <= (1 << n) - (1 << (n - winning_rounds)) + 1; i++) cout << i << " ";
    cout << endl;
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}