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

        bool flag = true;
        ll current_index = 0;
        vector<ll> ans;
        for (auto it : mp) {
            if (it.second < 2) {
                flag = false;
                break;
            } else {
                for (ll i = current_index + 1; i < current_index + it.second; i++) ans.push_back(i + 1);
                ans.push_back(current_index + 1);
                
                current_index += it.second;
            }
        }

        if (flag) {
            for (auto element : ans) cout << element << " ";
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}