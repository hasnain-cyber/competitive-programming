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
    string s = "ehfrzeevteeonoir";

    map<char, int> mp;
    for (char ch : s) {
        mp[ch]++;
    }

    vector<int> f(10, 0);

    // count 0 using z.
    int temp = mp['z'];
    f[0] += temp;
    mp['z'] -= temp;
    mp['e'] -= temp;
    mp['r'] -= temp;
    mp['o'] -= temp;

    // count 2 using w.
    temp = mp['w'];
    f[2] += temp;
    mp['t'] -= temp;
    mp['w'] -= temp;
    mp['o'] -= temp;

    // count 4 using u.
    temp = mp['u'];
    f[4] += temp;
    mp['f'] -= temp;
    mp['o'] -= temp;
    mp['u'] -= temp;
    mp['r'] -= temp;

    // count 6 uisng x.
    temp = mp['x'];
    f[6] += temp;
    mp['s'] -= temp;
    mp['i'] -= temp;
    mp['x'] -= temp;

    // count 8 uisng g.
    temp = mp['g'];
    f[8] += temp;
    mp['e'] -= temp;
    mp['i'] -= temp;
    mp['g'] -= temp;
    mp['h'] -= temp;
    mp['t'] -= temp;

    // count 1 uisng o.
    temp = mp['o'];
    f[1] += temp;
    mp['o'] -= temp;
    mp['n'] -= temp;
    mp['e'] -= temp;

    // count 3 uisng h.
    temp = mp['t'];
    f[3] += temp;
    mp['t'] -= temp;
    mp['h'] -= temp;
    mp['r'] -= temp;
    mp['e'] -= temp;
    mp['e'] -= temp;

    // count 5 uisng f.
    temp = mp['f'];
    f[5] += temp;
    mp['f'] -= temp;
    mp['i'] -= temp;
    mp['v'] -= temp;
    mp['e'] -= temp;

    // count 7 uisng s.
    temp = mp['s'];
    f[7] += temp;
    mp['s'] -= temp;
    mp['e'] -= temp;
    mp['v'] -= temp;
    mp['e'] -= temp;
    mp['n'] -= temp;

    // count 9 uisng i.
    temp = mp['i'];
    f[9] += temp;
    mp['n'] -= temp;
    mp['i'] -= temp;
    mp['n'] -= temp;
    mp['e'] -= temp;

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += (i * f[i]);
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve_testcase();
}