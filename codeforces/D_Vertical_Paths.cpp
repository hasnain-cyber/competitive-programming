#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

class Tree {
   private:
    vector<vector<int>> tree;

   public:
    Tree(int n1) {
        tree = vector<vector<int>>(n1 + 1);
    }

    void add_edge(int parent, int child) {
        tree[parent].push_back(child);
    }

    void get_components(int node, vector<int> &curr, vector<vector<int>> &ans) {
        vector<int> children = tree[node];

        if (children.size() == 0) {
            curr.push_back(node);
            ans.push_back(curr);
        } else {
            curr.push_back(node);
            get_components(children[0], curr, ans);

            for (int i = 1; i < children.size(); i++) {
                curr.clear();
                get_components(children[i], curr, ans);
            }
        }
    }
};

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Tree tree(n);
    int root;
    for (int i = 0; i < n; i++) {
        if (i + 1 == arr[i]) {
            root = i + 1;
        } else {
            tree.add_edge(arr[i], i + 1);
        }
    }

    vector<int> curr;
    vector<vector<int>> ans;
    tree.get_components(root, curr, ans);
    cout << ans.size() << endl;
    for (auto ele : ans) {
        cout << ele.size() << endl;
        print_arr(ele);
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}