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
    int value;
    SegmentTreeNode* left;
    SegmentTreeNode* right;

    SegmentTreeNode(int start1, int end1, int value1) {
        start = start1;
        end = end1;
        value = value1;

        left = NULL;
        right = NULL;
    }

    SegmentTreeNode(int start1, int end1, int value1, SegmentTreeNode* left1, SegmentTreeNode* right1) {
        start = start1;
        end = end1;
        value = value1;

        left = left1;
        right = right1;
    }
};

class SegmentTree {
private:
    SegmentTreeNode* root;

    SegmentTreeNode* build(vector<int>& arr, int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, arr[start]);
        }

        int mid = start + (end - start) / 2;
        SegmentTreeNode* left = build(arr, start, mid);
        SegmentTreeNode* right = build(arr, mid + 1, end);

        return new SegmentTreeNode(start, end, (left->value * right->value) % MOD, left, right);
    }

    int query(int start, int end, SegmentTreeNode* root) {
        if (root == NULL || root->start > end || root->end < start) {
            return 1;
        }

        if (root->start >= start && root->end <= end) {
            return root->value;
        }

        int mid = root->start + (root->end - root->start) / 2;
        int left = query(start, end, root->left);
        int right = query(start, end, root->right);

        return (left * right) % MOD;
    }

public:
    SegmentTree(vector<int>& arr) {
        int n = arr.size();
        root = build(arr, 0, n - 1);
    }

    int query(int start, int end) {
        return query(start, end, root);
    }
};

vector<pair<int, int>> condense(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || ans.back().first != arr[i]) {
            ans.push_back({ arr[i], 1 });
        }
        else {
            ans.back().second++;
        }
    }

    return ans;
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    auto condensed_arr = condense(arr);
    n = condensed_arr.size();
    vector<int> freq(n);
    for (int i = 0; i < n; i++) freq[i] = condensed_arr[i].second;

    SegmentTree tree(freq);

    int ans = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        if (condensed_arr[i + m - 1].first - condensed_arr[i].first == m - 1) {
            ans = (ans + tree.query(i, i + m - 1)) % MOD;
        }
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}