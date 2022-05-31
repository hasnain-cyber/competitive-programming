#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll solve(string s1, string s2, ll n, ll index, ll current_score) {
    if (index == n) {
        return current_score;
    } else if (s2[index] == '0') {
        return solve(s1, s2, n, index + 1, current_score);
    } else {
        if (index == 0) {
            if (s1[index + 1] == '1') {
                string temp_s1 = s1;
                temp_s1[index + 1] = '0';
                return max(solve(temp_s1, s2, n, index + 1, current_score + 1), solve(s1, s2, n, index + 1, current_score));
            } else {
                return solve(s1, s2, n, index + 1, current_score + (s1[index] == '0' ? 1 : 0));
            }
        } else if (index == n - 1) {
            if (s1[index - 1] == '1') {
                string temp_s1 = s1;
                temp_s1[index - 1] = '0';
                return max(solve(temp_s1, s2, n, index + 1, current_score + 1), solve(s1, s2, n, index + 1, current_score));
            } else {
                return solve(s1, s2, n, index + 1, current_score + (s1[index] == '0' ? 1 : 0));
            }
        } else {
            if (s1[index - 1] == '1' && s1[index + 1] == '1') {
                string temp_s1 = s1;
                temp_s1[index - 1] = '0';
                temp_s1[index + 1] = '0';
                return max(solve(temp_s1, s2, n, index + 1, current_score + 1), solve(s1, s2, n, index + 1, current_score));
            } else if (s1[index - 1] == '1') {
                string temp_s1 = s1;
                temp_s1[index - 1] = '0';
                return max(solve(temp_s1, s2, n, index + 1, current_score + 1), solve(s1, s2, n, index + 1, current_score));
            } else if (s1[index + 1] == '1') {
                string temp_s1 = s1;
                temp_s1[index + 1] = '0';
                return max(solve(temp_s1, s2, n, index + 1, current_score + 1), solve(s1, s2, n, index + 1, current_score));
            } else {
                return solve(s1, s2, n, index + 1, current_score + (s1[index] == '0' ? 1 : 0));
            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        cout << solve(s1, s2, n, 0, 0) << endl;
    }
}