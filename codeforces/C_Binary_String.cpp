#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        ll current = 0, ans = 0;
        for (ll i = 0; i < s.size(); i++) {
            int value = abs(s[i] - '0');
            current += value;

            current = max(current, (ll)0);
            ans = max(current, ans);
        }
    }
}