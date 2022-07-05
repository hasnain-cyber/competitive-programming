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
    t = 1;
    while (t--) {
        int n, s;
        cin >> n >> s;
        
        if (2 * n >= s + 1)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n - 1; i++) cout << 1 << " ";
            cout << s - n + 1 << endl;
            cout << n << endl;
        }
    }
}