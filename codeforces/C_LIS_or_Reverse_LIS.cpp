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
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];

        map<ll, ll> mp;
        for (ll i = 0; i < n; i++) mp[arr[i]]++;

        ll count1 = 0, count2 = 0;
        for (auto it : mp) {
            if (it.second == 1)
                count1++;
            else
                count2++;
        }

        cout << count2 + ceil(count1 / 2.0) << endl;
    }
}