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
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = MAX;
        int required_value = 0;
        int counter1 = 0, counter2 = 0;
        for (int i = 0; i < n; i++) {
            int current_value = (s[i] == 'r' ? 0 : 1);

            if (current_value == 0 && required_value == 1) counter1++;
            if (current_value == 1 && required_value == 0) counter2++;

            required_value = (required_value + 1) % 2;
        }
        ans = min(ans, max(counter1, counter2));

        required_value = 1;
        counter1 = 0, counter2 = 0;
        for (int i = 0; i < n; i++) {
            int current_value = (s[i] == 'r' ? 0 : 1);

            if (current_value == 0 && required_value == 1) counter1++;
            if (current_value == 1 && required_value == 0) counter2++;

            required_value = (required_value + 1) % 2;
        }
        ans = min(ans, max(counter1, counter2));

        cout << ans << endl;
    }
}