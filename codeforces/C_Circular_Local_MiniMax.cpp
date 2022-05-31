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
        sort(arr, arr + n);

        ll ans[n];
        ll pointer = 0;
        for (ll i = 0; 2 * i + 1 < n; i++) {
            ans[2 * i + 1] = arr[pointer];
            pointer++;
        }
        for (ll i = 0; 2 * i < n; i++) {
            ans[2 * i] = arr[pointer];
            pointer++;
        }

        bool flag = true;
        for (ll i = 1; i < n - 1; i++) {
            if (!((ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) || (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]))) {
                flag = false;
                break;
            }
        }
        if (!((ans[n - 2] > ans[n - 1] && ans[n - 1] < ans[0]) || (ans[n - 1] > ans[n - 2] && ans[n - 1] > ans[0]))) flag = false;

        if (flag) {
            cout << "YES" << endl;
            for (ll i = 0; i < n; i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}