#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num x, y, n;
    cin >> x >> y >> n;

    num answer;
    if (n == 1)
        answer = x;
    else if (n == 2)
        answer = y;
    else {
        num remainder = (n - 3) % 6;
        if (remainder == 0)
            answer = y - x;
        else if (remainder == 1)
            answer = -x;
        else if (remainder == 2)
            answer = -y;
        else if (remainder == 3)
            answer = x - y;
        else if (remainder == 4)
            answer = x;
        else
            answer = y;
    }

    cout << ((answer % MOD) + MOD) % MOD << endl;
}

// correct