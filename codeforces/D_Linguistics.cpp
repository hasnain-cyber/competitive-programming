#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool solve(string s, ll counter1, ll counter2, ll counter3, ll counter4) {
    if (counter1 < 0 || counter2 < 0 || counter3 < 0 || counter4 < 0) return false;

    ll n = s.size();

    if (n == 0)
        return counter1 == 0 && counter2 == 0 && counter3 == 0 && counter4 == 0;
    else if (n == 1) {
        if (s == "A")
            return counter1 == 1 && counter2 == 0 && counter3 == 0 && counter4 == 0;
        else if (s == "B")
            return counter2 == 1 && counter1 == 0 && counter3 == 0 && counter4 == 0;
        else
            return false;
    } else {
        if (s[0] == 'A') {
            bool value1 = solve(s.substr(1), counter1 - 1, counter2, counter3, counter4);
            bool value2 = false;
            if (s[1] == 'B')
                value2 = solve(s.substr(2), counter1, counter2, counter3 - 1, counter4);

            return value1 || value2;
        } else {
            bool value1 = solve(s.substr(1), counter1, counter2 - 1, counter3, counter4);
            bool value2 = false;
            if (s[1] == 'A')
                value2 = solve(s.substr(2), counter1, counter2, counter3, counter4 - 1);

            return value1 || value2;
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        ll n = s.size();

        if (solve(s, a, b, c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}