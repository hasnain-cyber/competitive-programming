#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num length;
    cin >> length;
    num arr[length];
    for (int i = 0; i < length; i++)
        cin >> arr[i];

    // generate all primes upto 10**5
    num n = pow(10, 6) + 1;
    bool sieve[n];
    fill_n(sieve, n, true);
    for (num i = 3; i < sqrt(n) + 1; i += 2) {
        if (sieve[i]) {
            for (num j = i * i; j < n; j += 2 * i) {
                sieve[j] = false;
            }
        }
    }

    set<num> answer_set = {2};
    for (num i = 3; i < n; i += 2) {
        if (sieve[i]) {
            answer_set.insert(i);
        }
    }

    for (num i = 0; i < length; i++) {
        if (sqrt(arr[i]) == num(sqrt(arr[i])) && answer_set.count(sqrt(arr[i])))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// correct