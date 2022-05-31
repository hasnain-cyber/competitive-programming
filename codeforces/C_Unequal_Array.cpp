#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;
        num arr[n];
        for (num i = 0; i < n; i++) cin >> arr[i];

        num counter = 0;
        for (num i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                if (i + 3 != n) {
                    if (arr[i + 2] == arr[i + 3]) {
                        counter += 2;
                        i += 3;
                    } else {
                        counter++;
                        i += 1;
                    }
                } else {
                    counter++;
                    i += 1;
                }
            }
        }

        cout << counter << endl;
    }
}

// wrong answer