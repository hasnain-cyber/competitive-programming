#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;
        string s;
        cin >> s;

        num counter_0 = 0, counter_1 = 0;
        for (num i = 0; i < n; i++) {
            if (s[i] == '0')
                counter_0++;
            else
                counter_1++;
        }

        if (counter_0 == counter_1) {
            cout << counter_0 + counter_1 << endl;
        } else {
            cout << 2 * min(counter_0, counter_1) + 1 << endl;
        }
    }
}

// correct