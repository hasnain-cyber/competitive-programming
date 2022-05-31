#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool solve(vector<ll> arr) {
    if (arr.size() == 1) return true;

    ll max_index = max_element(arr.begin(), arr.end()) - arr.begin();

    vector<ll> temp1, temp2;
    for (ll i = 0; i < max_index; i++) temp1.push_back(arr[i]);
    for (ll i = max_index + 1; i < arr.size(); i++) temp1.push_back(arr[i]);

    if (temp1.size() > 0 && temp2.size() > 0)
        return solve(temp1) && solve(temp2);
    else if (temp1.size() > 0)
        return solve(temp1);
    else
        return solve(temp2);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr;
        for (ll i = 0; i < n; i++) {
            ll value;
            cin >> value;
            arr.push_back(value);
        }

        if (solve(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}