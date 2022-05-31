#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    string n;
    num a, b;
    cin >> n;
    cin >> a >> b;

    num n_digits = n.size();
    bool prefix_division_arr[n_digits];
    num previous_sum = 0;
    for (num i = 0; i < n_digits; i++) {
        num new_sum = (previous_sum + stoll(string(1, n[i]), nullptr, 10) % a) % a;
        if (new_sum == 0) {
        }
        previous_sum = new_sum;
    }
}

// could not solve