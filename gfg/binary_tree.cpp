#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;

    Node(int data1) {
        data = data1;
    }
};

class Tree {
   public:
    Node* createTree() {
        Node* root = NULL;
        cout << "Enter data for node: ";
        int value;
        cin >> value;
        if (value == -1)
            return NULL;
        else {
            root = new Node(value);
            cout << "Enter left for " << value << endl;
            root->left = createTree();
            cout << "Enter right for " << value << endl;
            root->right = createTree();

            return root;
        }
    }

    void inorder_traversal(Node* root) {
        if (root == NULL) return;

        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }

    void level_order_traversal(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }

    int height(Node* root) {
        if (root == NULL)
            return 0;
        else {
            return 1 + max(height(root->left), height(root->right));
        }
    }

    int size(Node* root) {
        if (root == NULL)
            return 0;
        else {
            return 1 + size(root->left) + size(root->right);
        }
    }

    int max_value(Node* root) {
        if (root == NULL)
            return -1;
        else {
            return max(root->data, max(max_value(root->left), max_value(root->right)));
        }
    }

    void left_view(Node* root, int level, set<int>& s) {
        if (root == NULL) return;

        if (!s.count(level)) {
            cout << root->data << " ";
            s.insert(level);
        }

        left_view(root->left, level + 1, s);
        left_view(root->right, level + 1, s);
    }

    void left_view(Node* root, int horizontal_distance, map<int, int>& mp) {
        if (root == NULL) return;

        if (!mp.count(horizontal_distance)) mp[horizontal_distance] = root->data;

        left_view(root->left, horizontal_distance - 1, mp);
        left_view(root->right, horizontal_distance + 1, mp);
    }

    void convert_to_dll(Node* root) {
    }

    // max distance bw two leaf nodes.
    int diameter(Node* root, int& ans) {
        if (root == NULL) return 0;

        int lh = height(root->left), rh = height(root->right);
        ans = max(ans, 1 + lh + rh);

        return 1 + max(lh, rh);
    }

    Node* lowest_common_ancestor(Node* root, int n1, int n2) {
        if (root == NULL)
            return NULL;
        else if (root->data == n1 || root->data == n2)
            return root;
        else {
            Node* left = lowest_common_ancestor(root->left, n1, n2);
            Node* right = lowest_common_ancestor(root->right, n1, n2);

            if (left == NULL) return right;
            if (right == NULL) return left;

            return root;
        }
    }
};

int main() {
    Tree tree;
    Node* root = tree.createTree();
    // tree.inorder_traversal(root);
    // cout << tree.height(root) << endl;
    // cout << tree.size(root) << endl;
    // cout << tree.max_value(root) << endl;
    // tree.level_order_traversal(root);

    // set<int> temp;
    // tree.left_view(root, 1, temp);

    // map<int, int> temp;
    // tree.left_view(root, 1, temp);
    // for(auto it: temp) cout << it.second << " ";

    // Node* head = NULL;
    // tree.convert_to_dll(head);

    // int ans = 0;
    // tree.diameter(root, ans);
    // cout << ans << endl;
}
