#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n, m;
    cin >> n >> m;

    num value1 = n / m, value2 = n % m;
    num k_min = (value1 * (value1 + 1) / 2) * value2 + (value1 * (value1 - 1) / 2) * (m - value2), k_max = (n - m) * (n - m + 1) / 2;

    cout << k_min << " " << k_max << endl;
}

// correct