#include <bits/stdc++.h>

#define MOD 1000000007
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
        string s;
        cin >> s;
        int n = s.size();

        int counter1 = 0, counter2 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                counter1++;
            else if (s[i] == '[')
                counter2++;
            else if (s[i] == ')') {
                if (counter1 != 0) {
                    counter1--;
                    ans++;
                }
            } else {
                if (counter2 != 0) {
                    counter2--;
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}