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

    Node(int x) {
        data = x;
    }
};

class BST {
    bool search(Node* root, int x) {
        if (root == NULL) return false;

        if (root->data == x)
            return true;
        else if (root->data < x)
            return search(root->right, x);
        else
            return search(root->left, x);
    }

    // insert, without balancing
    Node* insert_recursively(Node* root, int x) {
        if (root == NULL) return new Node(x);

        if (root->data > x)
            root->left = insert_recursively(root->left, x);
        else if (root->data < x)
            root->right = insert_recursively(root->right, x);

        return root;
    }

    // insert, without balancing
    Node* insert_iteratively(Node* root, int x) {
        Node* new_node = new Node(x);

        Node* curr = root;
        Node* parent = NULL;
        while (curr != NULL) {
            parent = curr;
            if (curr->data < x)
                curr = curr->right;
            else if (curr->data > x)
                curr = curr->left;
        }

        if (parent == NULL)
            return new_node;
        else {
            if (parent->data < x)
                parent->right = new_node;
            else if (parent->data > x)
                parent->left = new_node;

            return root;
        }
    }

    int min_value(Node* root) {
        if (root == NULL) return NULL;

        return min(root->data, min(min_value(root->left), min_value(root->right)));
    }

    Node* delete_node(Node* root, int x) {
        if (root == NULL) return NULL;

        if (root->data > x)
            root->left = delete_node(root->right, x);
        else if (root->data < x)
            root->right = delete_node(root->right, x);
        else {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;
            else {
                root->data = min_value(root->right);
                root->right = delete_node(root->right, root->data);
            }
        }

        return root;
    }

    bool verify(Node* root, int min_range, int max_range) {
        if (root == NULL) return true;

        if (root->data <= min_range || root->data >= max_range) return false;

        return verify(root->left, min_range, root->data) && verify(root->right, root->data, max_range);
    }
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];
    }
}