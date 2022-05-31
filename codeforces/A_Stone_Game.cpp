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
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ll min_element_index = min_element(arr, arr + n) - arr, max_element_index = max_element(arr, arr + n) - arr;
        ll a = min(min_element_index, max_element_index), b = max(min_element_index, max_element_index);

        ll answer1 = min(b + 1, n - a);
        ll answer2 = (a + 1) + (n - b );
        cout << min(answer1, answer2) << endl;
    }
}