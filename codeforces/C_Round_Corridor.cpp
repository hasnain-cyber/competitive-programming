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
        int n, m, q;
        cin >> n >> m >> q;

        int gcd_value = __gcd(n, m);
        vector<int> values;
        int current_value = 0;
        while(values.size() < gcd_value) {
            values.push_back(current_value);
            current_value += 
        }

        while (q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
        }
    }
}