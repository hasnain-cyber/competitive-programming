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
        ll length = s.size();

        if (length == 2) {
            cout << s[1] << endl;
        } else {
            int min_digit = s[0];
            for (ll i = 0; i < length; i++) {
                string temp;
                temp += s[i];
                int check_digit = stoi(temp);

                min_digit = min(min_digit, check_digit);
            }

            cout << min_digit << endl;
        }
    }
}

// correct