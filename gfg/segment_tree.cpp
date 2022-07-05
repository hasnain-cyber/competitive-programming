#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void buildTree(vector<int> &tree, const vector<int> &arr, int index, int s, int e) {
    if (s > e) return;

    if (s == e) {
        tree[index] = arr[s];
        return;
    }

    int mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);

    int left = tree[2 * index];
    int right = tree[2 * index + 1];
    tree[index] = min(left, right);
}

int rangeMinimumQueryLazy(vector<int> &tree, vector<int> &lazy, int index, int s, int e, int qs, int qe) {
    // no overlap
    if (qs > e || qe < s) return INT_MAX;

    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        if (s != e) {  // if not leaf node
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // total overlap
    if (qs <= s && qe >= e) return tree[index];

    // partial overlap
    int mid = (s + e) / 2;
    return min(rangeMinimumQueryLazy(tree, lazy, 2 * index, s, mid, qs, qe), rangeMinimumQueryLazy(tree, lazy, 2 * index + 1, mid + 1, e, qs, qe));
}

void updateSegmentTreeRangeLazily(vector<int> &tree, vector<int> &lazy, int index, int s, int e, int delta, int qs, int qe) {
    if (s > e) return;

    // make sure propagation is already done at current position
    if (lazy[index] != 0) {
        tree[index] += lazy[index];

        // if not a leaf node
        if (s != e) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // if no overlap occurs
    if (qs > e || qe < s) return;

    // total overlap
    if (qs <= s && qe >= e) {
        tree[index] += delta;
        if (s != e) {
            lazy[2 * index] += delta;
            lazy[2 * index + 1] += delta;
        }
        return;
    }

    // otherwise, for partial overlap, look both left and right.
    int mid = (s + e) / 2;
    updateSegmentTreeRangeLazily(tree, lazy, 2 * index, s, mid, delta, qs, qe);
    updateSegmentTreeRangeLazily(tree, lazy, 2 * index + 1, mid + 1, e, delta, qs, qe);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int main() {
    vector<int> arr = {1, 3, 2, -2, 4, 5};
    int n = arr.size();

    vector<int> tree(4 * n + 1, -1);
    vector<int> lazy(4 * n + 1, 0);
    buildTree(tree, arr, 1, 0, n - 1);

    int q = 5;
    while (q--) {
        cout << "Enter query: ";
        int qs, qe;
        cin >> qs >> qe;
        cout << rangeMinimumQueryLazy(tree, lazy, 1, 0, n - 1, qs, qe) << endl;
    }
}