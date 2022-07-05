#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (s.find("aa") != string::npos)
            cout << 2 << endl;
        else if (s.find("aba") != string::npos || s.find("aca") != string::npos)
            cout << 3 << endl;
        else if (s.find("abca") != string::npos || s.find("acba") != string::npos)
            cout << 4 << endl;
        else if (s.find("abbacca") != string::npos || s.find("accabba") != string::npos)
            cout << 7 << endl;
        else
            cout << -1 << endl;
    }
}