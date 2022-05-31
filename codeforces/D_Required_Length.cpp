#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

ll solve(ll n, ll current_number, map<ll, ll> &dp) {
    set<int> digits;
    ll number_of_digits = 0;

    ll temp = current_number;
    while (temp > 0) {
        number_of_digits++;
        digits.insert(temp % 10);
        temp /= 10;
    }

    if (number_of_digits == n)
        return 0;
    else if (number_of_digits > n)
        return -1;
    else {
        ll min_operations = -1;
        for (ll digit : digits) {
            if (digit == 1) continue;

            if (!dp.count(current_number * digit))
                dp[current_number * digit] = solve(n, current_number * digit, dp) + 1;

            if (dp[current_number * digit] != 0) {
                if (min_operations != -1)
                    min_operations = min(min_operations, dp[current_number * digit]);
                else
                    min_operations = dp[current_number * digit];
            }
        }

        dp[current_number] = min_operations;
        return dp[current_number];
    }
}

int main() {
    ll n, x;
    cin >> n >> x;

    map<ll, ll> dp;
    cout << solve(n, x, dp) << endl;
}

// correct