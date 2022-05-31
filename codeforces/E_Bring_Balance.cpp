#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll counter = 0;
        vector<pair<ll, ll>> ans;
        ll start = -1, end = -1;
        for (ll i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (counter >= 0) {
                    counter++;
                } else {
                    counter++;
                    if (counter == 0) {
                        end = i;
                        ans.push_back(make_pair(start, end));
                        start = -1;
                        end = -1;
                    }
                }
            } else {
                if (counter == 0) {
                    counter--;
                    start = i;
                } else if (counter < 0) {
                    counter--;
                } else {
                    counter--;
                }
            }
        }

        cout << ans.size() << endl;
        for (ll i = 0; i < ans.size(); i++) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }
    }
}