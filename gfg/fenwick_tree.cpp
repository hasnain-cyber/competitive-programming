#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

// this will give prefix sum of element one less than the current element.
class BIT {
    ll n;
    vector<ll> tree;

   public:
    BIT(ll n1) {
        // index in tree is one more, so size is one more too.
        n = n1 + 1;
        tree = vector<ll>(n, 0);
    }

    void construct_tree(vector<ll> &arr) {
        for (int i = 0; i < n - 1; i++) update(i, arr[i]);
    }

    void update(ll i, ll delta) {
        // index in tree is one more than that in array
        i++;

        while (i <= n) {
            tree[i] += delta;

            // add the lowest set bit.
            i += (i & -i);
        }
    }

    ll prefix_sum(ll i) {
        // index in tree is one more than that in array, but since we want prefix sum, so we leave current element, and thus, leave index as it is.

        ll s = 0;
        while (i > 0) {
            s += tree[i];

            // remove the lowest set bit.
            i -= (i & -i);
        }
        return s;
    }
};

int main() {
    vector<ll> arr = {1, 2, 3, 4, 5};
    ll n = arr.size();

    BIT bit = BIT(n);
    bit.construct_tree(arr);
}