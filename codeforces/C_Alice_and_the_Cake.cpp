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
        priority_queue<ll> p1, p2;
        ll total_weight = 0;
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            total_weight += arr[i];
            p1.push(arr[i]);
        }

        p2.push(total_weight);
        while (!p1.empty() && !p2.empty()) {
            if (p1.top() == p2.top()) {
                p1.pop();
                p2.pop();
            } else if (p1.top() > p2.top())
                break;
            else {
                ll current_weight = p2.top();
                p2.pop();
                ll w1 = floor(current_weight / 2.0), w2 = ceil(current_weight / 2.0);
                p2.push(w1);
                p2.push(w2);
            }
        }

        if (p1.empty() && p2.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}