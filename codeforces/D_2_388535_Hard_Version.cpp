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

struct Node {
    Node* left, * right;
    Node() {
        left = right = NULL;
    }
};

class Trie {
private:
    Node* root = new Node();

public:
    void add(int n) {
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (curr->left == NULL) curr->left = new Node();
                curr = curr->left;
            }
            else {
                if (curr->right == NULL) curr->right = new Node();
                curr = curr->right;
            }
        }
    }

    int find_max(int n) {
        Node* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (curr->right) {
                    ans += (1 << i);
                    curr = curr->right;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->left) {
                    ans += (1 << i);
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
        }

        return ans;
    }

    int find_min(int n) {
        Node* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (bit == 0) {
                if (curr->left) {
                    curr = curr->left;
                }
                else {
                    ans += (1 << i);
                    curr = curr->right;
                }
            }
            else {
                if (curr->right) {
                    curr = curr->right;
                }
                else {
                    ans += (1 << i);
                    curr = curr->left;
                }
            }
        }

        return ans;
    }
};

void solve_testcase() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // create a trie for the arr bits upper to lower bit
    Trie trie;
    for (int i = 0; i < n; i++) {
        trie.add(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int candidate = (l ^ arr[i]);

        int mn = trie.find_min(candidate);
        int mx = trie.find_max(candidate);

        if (mn == l && mx == r) {
            cout << candidate << endl;
            return;
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