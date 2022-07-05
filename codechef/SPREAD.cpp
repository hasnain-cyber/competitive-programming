#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

class SegmentTree {
   private:
    void build_tree_helper(vector<ll> &arr, ll index, ll s, ll e) {
        if (s > e) return;

        if (s == e) {
            tree[index] = arr[s];
            return;
        }

        ll mid = (s + e) / 2;
        build_tree_helper(arr, 2 * index, s, mid);
        build_tree_helper(arr, 2 * index + 1, mid + 1, e);

        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
        return;
    }

    void
    update_segment_tree_lazily_helper(ll index, ll s, ll e, ll qs, ll qe, ll delta) {
        if (s > e) return;

        // update if not up to date.
        if (lazy[index] != 0) {
            tree[index] += lazy[index];
            if (s != e) {  // if not leaf node
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }

        // no overlap.
        if (qe < s || qs > e) return;

        // total overlap.
        if (qs <= s && qe >= e) {
            tree[index] += delta;
            if (s != e) {
                lazy[2 * index] += delta;
                lazy[2 * index + 1] += delta;
            }
            return;
        }

        // partial overlap
        ll mid = (s + e) / 2;
        update_segment_tree_lazily_helper(2 * index, s, mid, qs, qe, delta);
        update_segment_tree_lazily_helper(2 * index + 1, mid + 1, e, qs, qe, delta);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);

        return;
    }

    ll query_segment_tree_lazily_helper(ll index, ll s, ll e, ll qs, ll qe) {
        if (s > e) return MAX;

        if (lazy[index] != 0) {
            tree[index] += lazy[index];
            if (s != e) {  // if not leaf node
                lazy[2 * index] += lazy[index];
                lazy[2 * index + 1] += lazy[index];
            }
            lazy[index] = 0;
        }

        // no overlap
        if (qe < s || qs > e) return MAX;

        // total overlap
        if (qs <= s && qe >= e) return tree[index];

        // partial overlap
        ll mid = (s + e) / 2;
        return min(query_segment_tree_lazily_helper(2 * index, s, mid, qs, qe), query_segment_tree_lazily_helper(2 * index + 1, mid + 1, e, qs, qe));
    }

   public:
    vector<ll> tree;
    vector<ll> lazy;
    ll n;

    SegmentTree(ll n1) {
        n = n1;
        tree = vector<ll>(4 * n + 1, 0);
        lazy = vector<ll>(4 * n + 1, 0);
    }

    // first function to call to actually build the tree.
    void
    build_tree(vector<ll> &arr) {
        return build_tree_helper(arr, 1, 0, n - 1);
    }

    // increment value in a range by delta
    void update_segment_tree_lazily(ll qs, ll qe, ll delta) {
        return update_segment_tree_lazily_helper(1, 0, n - 1, qs, qe, delta);
    }

    ll query_segment_tree_lazily(ll qs, ll qe) {
        return query_segment_tree_lazily_helper(1, 0, n - 1, qs, qe);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];
    }
}