#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int find_set_bits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (ans & 1);
        ans >>= 1;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = (int)pow(10, 12);

    set<int> factorials;
    int value = 6;
    int i = 3;
    while (value <= N) {
        factorials.insert(value);
        i++;
        value *= i;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int ans = MAX;
        for(int factorial: factorials) {
            
        }
    }
}