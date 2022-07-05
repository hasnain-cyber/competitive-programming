#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void solve(vector<char> &ans, ll i, ll j) {
    cout << "? 2 " << i + 1 << " " << j + 1 << endl;
    fflush(stdout);
    ll n_different;
    cin >> n_different;

    if (n_different == 1) {
        cout << "? 1 " << i + 1 << endl;
        fflush(stdout);
        char c;
        cin >> c;
        for (ll index = i; index <= j; index++) ans[index] = c;
        return;
    } else if (n_different == j - i + 1) {
        for (ll index = i; index <= j; index++) {
            cout << "? 1 " << index + 1 << endl;
            fflush(stdout);
            char c;
            cin >> c;
            ans[index] = c;
        }
        return;
    } else {
        ll mid = (i + j) / 2;
        solve(ans, i, mid);
        solve(ans, mid + 1, j);
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<char> ans(n);
    solve(ans, 0, n - 1);
    string s = "";
    for (auto c : ans) s += c;

    cout << "! " << s << endl;
}