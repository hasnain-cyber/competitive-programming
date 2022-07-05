#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int turn = 0, ans = 0;
        while (n > 0) {
            if (turn & 1) {
                if (n & 1 || (n % 4 == 0 && n > 4)) {
                    n--;
                } else {
                    n /= 2;
                }
            } else {
                if (n & 1 || (n % 4 == 0 && n > 4)) {
                    n--;
                    ans++;
                } else {
                    ans += n / 2;
                    n /= 2;
                }
            }

            turn++;
        }

        cout << ans << endl;
    }
}