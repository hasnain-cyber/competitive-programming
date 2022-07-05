#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        string c;
        ll p1 = 0, p2 = 0, counter1 = 0, counter2 = 0;
        while (p1 < n && p2 < m) {
            if (a[p1] < b[p2]) {
                if (counter1 < k) {
                    counter2 = 0;
                    counter1++;
                    c.push_back(a[p1]);
                    p1++;
                } else {
                    counter1 = 0;
                    counter2++;
                    c.push_back(b[p2]);
                    p2++;
                }
            } else if (a[p1] > b[p2]) {
                if (counter2 < k) {
                    counter1 = 0;
                    counter2++;
                    c.push_back(b[p2]);
                    p2++;
                } else {
                    counter2 = 0;
                    counter1++;
                    c.push_back(a[p1]);
                    p1++;
                }
            } else {
                if (counter1 < counter2) {
                    counter2 = 0;
                    counter1++;
                    c.push_back(a[p1]);
                    p1++;
                } else {
                    counter1 = 0;
                    counter2++;
                    c.push_back(b[p2]);
                    p2++;
                }
            }
        }

        cout << c << endl;
    }
}