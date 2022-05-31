#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll solve(string s, ll n, ll index, ll score1, ll score2) {
    if (index == n - 1) {
        return n;
    } else if (abs(score1 - score2) > (n - index - 1) / 2) {
        return index;
    } else {
        if (index & 1) {
            if (s[index] == '1') {
                return solve(s, n, index + 1, score1, score2 + 1);
            } else if (s[index] == '0') {
                return solve(s, n, index + 1, score1, score2);
            } else {
                return min(solve(s, n, index + 1, score1, score2 + 1), solve(s, n, index + 1, score1, score2));
            }
        } else {
            if (s[index] == '1') {
                return solve(s, n, index + 1, score1 + 1, score2);
            } else if (s[index] == '0') {
                return solve(s, n, index + 1, score1, score2);
            } else {
                return min(solve(s, n, index + 1, score1 + 1, score2), solve(s, n, index + 1, score1, score2));
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n = s.size();

        cout << solve(s, n, 0, 0, 0) << endl;
    }
}

// incompleted