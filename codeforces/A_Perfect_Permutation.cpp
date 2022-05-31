#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num n;
    cin >> n;

    if (n == 1 || n % 2 == 1) {
        cout << -1 << endl;
    } else {
        for (num i = 0; i < n; i += 2) {
            cout << i + 2 << " " << i + 1 << " ";
        }
    }
}

// correct
