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

        num index = s.find('8');
        if (index == -1 || n - index < 11) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}

// correct