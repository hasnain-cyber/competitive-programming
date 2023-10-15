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

class TrieNode {
public:
    TrieNode* left;
    TrieNode* right;

    TrieNode() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int value) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((value >> i) & 1);

            if (bit == 0) {
                if (!curr->left) curr->left = new TrieNode();
                curr = curr->left;
            }
            else {
                if (!curr->right) curr->right = new TrieNode();
                curr = curr->right;
            }
        }
    }

    int find(int value) {
        TrieNode* curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((value >> i) & 1);

            if (bit == 0) {
                if (curr->right) {
                    curr = curr->right;
                    ans |= (1 << i);
                }
                else if (curr->left) {
                    curr = curr->left;
                }
                else {
                    return ans;
                }
            }
            else {
                if (curr->left) {
                    curr = curr->left;
                    ans |= (1 << i);
                }
                else if (curr->right) {
                    curr = curr->right;
                }
                else {
                    return ans;
                }
            }
        }

        return ans;
    }
};

int find_max_xor_subArray(vector<int>& arr, int n) {
    Trie t;
    int ans = 0;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre ^= arr[i];
        t.insert(pre);
        ans = max(ans, pre);
        ans = max(ans, t.find(pre));
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << find_max_xor_subArray(arr, n) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}