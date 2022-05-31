#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

num count_lucky_digits(num n) {
    num counter = 0;
    while (n > 0) {
        num temp = n % 10;
        if (temp == 4 || temp == 7) {
            counter += 1;
        }
        n /= 10;
    }
    return counter;
}

int main() {
    num n, k;
    cin >> n >> k;
    num counter = 0;
    for (num i = 0; i < n; i++) {
        num temp;
        cin >> temp;
        if (count_lucky_digits(temp) <= k)
            counter += 1;
    }
    cout << counter;
}

// correct