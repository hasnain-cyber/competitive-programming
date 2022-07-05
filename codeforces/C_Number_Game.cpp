#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

void ashish() {
    cout << "Ashishgup" << endl;
}

void fastest() {
    cout << "FastestFinger" << endl;
}

bool check_prime(int n) {
    if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    else {
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) return false;
        }

        return true;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1)
            fastest();
        else if (n & 1 || n == 2)
            ashish();
        else {
            double temp = log2(n);
            if (temp == (int)temp) {
                fastest();
            } else {
                if ((n / 2) % 2 == 0)
                    ashish();
                else {
                    int check_value = n / 2;
                    if (check_prime(check_value))
                        fastest();
                    else
                        ashish();
                }
            }
        }
    }
}