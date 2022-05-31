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
        ll arr1[n], arr2[n];
        for (ll i = 0; i < n; i++) cin >> arr1[i];
        for (ll i = 0; i < n; i++) cin >> arr2[i];

        vector<pair<ll, ll>> ans;
        ll counter = 1;
        while (counter > 0) {
            counter = 0;

            for (ll i = 0; i < n - 1; i++) {
                if (arr1[i] > arr1[i + 1] || arr2[i] > arr2[i + 1] && (arr1[i] == arr1[i + 1] || arr2[i] == arr2[i + 1])) {
                    swap(arr1[i], arr1[i + 1]);
                    swap(arr2[i], arr2[i + 1]);

                    ans.push_back(make_pair(i + 2, i + 1));
                    counter++;
                }
            }
        }

        bool flag = true;
        for (ll i = 0; i < n - 1; i++) {
            if (arr1[i] > arr1[i + 1] || arr2[i] > arr2[i + 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << ans.size() << endl;
            for (ll i = 0; i < ans.size(); i++) {
                cout << ans[i].first << " " << ans[i].second << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}

// correct