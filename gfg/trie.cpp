#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

struct Node {
    char c;
    Node* children[26];
    bool isComplete;

    Node() {
        isComplete = false;
    }

    Node(char ch) {
        c = ch;
        isComplete = false;
    }
};

class Trie {
    Node* root;

   public:
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* curr = root;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (!curr->children[int(ch - 'a')]) curr->children[int(ch - 'a')] = new Node(ch);
            curr = curr->children[int(ch - 'a')];
        }
        curr->isComplete = true;
    }

    bool find(string s) {
        Node* curr = root;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (!curr->children[int(ch - 'a')]) return false;
            curr = curr->children[int(ch - 'a')];
        }
        return curr->isComplete;
    }
};

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first || (p1.first == p2.first && p1.second > p2.second);
}

vector<int> solve(string s, vector<string>& arr) {
    Trie t;

    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            if (temp.size() > 0) {
                t.insert(temp);
                temp = "";
            }
        } else
            temp.push_back(s[i]);
    }
    if (temp.size() > 0) {
        t.insert(temp);
        temp = "";
    }

    vector<pair<int, int>> temp_ans;  // count, j
    for (int j = 0; j < arr.size(); j++) {
        string var = arr[j];

        int count = 0;
        string temp = "";
        for (int i = 0; i < var.size(); i++) {
            if (var[i] == '_') {
                if (temp.size() > 0) {
                    count += t.find(temp);
                    temp = "";
                }
            } else
                temp.push_back(var[i]);
        }
        if (temp.size() > 0) {
            count += t.find(temp);
            temp = "";
        }

        cout << var << " " << count << endl;    
        temp_ans.push_back({count, j});
    }

    sort(temp_ans.begin(), temp_ans.end(), compare);

    vector<int> ans;
    for (auto val : temp_ans) ans.push_back(val.second);

    return ans;
}

int main() {
    vector<string> arr = {"smart_guy", "girl_and_boy_play", "play_ground"};
    vector<int> ans = solve("play_boy", arr);

    for (auto element : ans) cout << element << " ";
    cout << endl;
}