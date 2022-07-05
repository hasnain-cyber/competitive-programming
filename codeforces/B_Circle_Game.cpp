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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) cin >> arr[i];

        if (n % 2 == 0) {
            ll min_value_index = min_element(arr.begin(), arr.end()) - arr.begin();
            if (min_value_index % 2 == 0)
                cout << "Joe" << endl;
            else
                cout << "Mike" << endl;
        } else
            cout << "Mike" << endl;
    }
}