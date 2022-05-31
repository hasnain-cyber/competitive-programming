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
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (n == 1 && s[0] == '?') {
            cout << 'B' << endl;
        } else {
            ll counter = count(s.begin(), s.end(), '?');
            while (counter > 0) {
                for (ll i = 1; i < n; i++) {
                    if (s[i] == '?' && s[i - 1] != '?') {
                        if (s[i - 1] == 'R')
                            s[i] = 'B';
                        else
                            s[i] = 'R';
                        counter--;
                    }
                }
                for (ll i = 0; i < n - 1; i++) {
                    if (s[i] == '?' && s[i + 1] != '?') {
                        if (s[i + 1] == 'R')
                            s[i] = 'B';
                        else
                            s[i] = 'R';
                        counter--;
                    }
                }
            }
            cout << s << endl;
        }
    }
}

// tle