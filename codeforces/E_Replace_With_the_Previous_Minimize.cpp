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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        char max_char = 'a';
        for (int i = 0; i < n && k > 0; i++) {
            if (s[i] <= max_char) continue;

            if (s[i] - 'a' <= k)
                max_char = s[i];
            else {
                // this many moves will be spent anyways for max_char
                k -= max_char - 'a';

                char current_char = s[i];
                char final_char = s[i] - k;
                for (int j = 0; j < n; j++) {
                    if (s[j] > final_char && s[j] <= current_char) s[j] = final_char;
                }
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] <= max_char) s[i] = 'a';
        }

        cout << s << endl;
    }
}