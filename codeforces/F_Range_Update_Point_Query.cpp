#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

class SegmentTreeNode {
public:
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int start, int end) : start(start), end(end), sum(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
private:
    SegmentTreeNode* root;

    SegmentTreeNode* buildTree(const std::vector<int>& arr, int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end);
        }

        int mid = (start + end) / 2;
        SegmentTreeNode* leftNode = buildTree(arr, start, mid);
        SegmentTreeNode* rightNode = buildTree(arr, mid + 1, end);

        SegmentTreeNode* node = new SegmentTreeNode(start, end);
        node->left = leftNode;
        node->right = rightNode;

        return node;
    }

    int query(SegmentTreeNode* node, int start, int end) {
        if (node == nullptr || end < node->start || start > node->end) {
            return 0;
        }

        if (start <= node->start && end >= node->end) {
            return node->sum;
        }

        int leftSum = query(node->left, start, end);
        int rightSum = query(node->right, start, end);

        return leftSum + rightSum;
    }

    void update(SegmentTreeNode* node, int index, int diff) {
        if (node == nullptr || index < node->start || index > node->end) {
            return;
        }

        node->sum += diff;

        if (node->start != node->end) {
            update(node->left, index, diff);
            update(node->right, index, diff);
        }
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        int n = arr.size();
        if (n > 0) {
            root = buildTree(arr, 0, n - 1);
            for (int i = 0; i < n; ++i) {
                update(root, i, arr[i]);
            }
        }
    }

    int query(int start, int end) {
        if (root == nullptr || start > end) {
            return 0;
        }
        return query(root, start, end);
    }

    void update(int index, int newValue) {
        if (root == nullptr || index < 0 || index > root->end) {
            return;
        }

        int oldValue = query(index, index);
        int diff = newValue - oldValue;
        update(root, index, diff);
    }
};

int sum_of_digits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int perform_operations(int n, int k) {
    int ans = n;
    for (int i = 0; i < k && ans > 9; i++) {
        ans = sum_of_digits(ans);
    }
    return ans;
}

void solve_testcase() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dummy(n, 0);
    SegmentTree tree(dummy);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            tree.update(l, tree.query(l, l) + 1);
            if (r + 1 < n) {
                tree.update(r + 1, tree.query(r + 1, r + 1) - 1);
            }
        }
        else {
            int idx;
            cin >> idx;
            idx--;

            cout << perform_operations(arr[idx], tree.query(0, idx)) << endl;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}