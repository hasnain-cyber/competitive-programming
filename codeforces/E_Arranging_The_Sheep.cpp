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
        string arr;
        cin >> arr;

        int i = 0, j = n - 1;
        int counter1 = 0, counter2 = 0;
        int ans = 0;

        while (i <= j) {
            if (arr[i] == '*') {
                i++;
                counter1++;
            } else if (arr[j] == '*') {
                j--;
                counter2++;
            } else {
                if (counter1 <= counter2) {
                    i++;
                    ans += counter1;
                } else {
                    j--;
                    ans += counter2;
                }
            }
        }

        cout << ans << endl;
    }
}