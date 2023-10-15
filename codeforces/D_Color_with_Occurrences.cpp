// #include <bits/stdc++.h>

// #define MOD 1000000007
// // #define MOD 998244353
// #define infinity numeric_limits<int>::max()

// #define int long long int
// #define double long double

// #define endl '\n'

// using namespace std;

// template <typename T>
// void print_arr(vector<T>& arr) {
//     for (T element : arr)
//         cout << element << ' ';
//     cout << endl;
// }

// void solve(int i, int n, vector<int>& jump_arr, vector<string>& arr, vector<pair<int, int>>& curr, vector<pair<int, int>>& ans, vector<bool>& visited) {
//     if (i >= n) {
//         if (ans.empty() || ans.size() > curr.size()) ans = curr;
//         return;
//     }
//     if (jump_arr[i] == -1 || visited[i]) return;
//     visited[i] = true;

//     for (int k = arr[jump_arr[i]].size(); k >= 1; k--) {
//         curr.push_back({ jump_arr[i] + 1, i + 1 });
//         solve(i + k, n, jump_arr, arr, curr, ans, visited);
//         curr.pop_back();
//     }
// }

// void solve_testcase() {
//     string s;
//     cin >> s;

//     int temp;
//     cin >> temp;
//     vector<string> arr(temp);
//     for (int i = 0; i < temp; i++) cin >> arr[i];

//     vector<int> jump_arr(s.size(), (int)-1);
//     for (int i = 0; i < s.size(); i++) {
//         for (int j = 0; j < arr.size(); j++) {
//             if (s.substr(i, arr[j].size()) == arr[j] && (jump_arr[i] == -1 || arr[jump_arr[i]].size() < arr[j].size())) {
//                 jump_arr[i] = j;
//             }
//         }
//     }

//     vector<pair<int, int>> ans, curr;
//     vector<bool> visited(s.size(), false);
//     solve(0, s.size(), jump_arr, arr, curr, ans, visited);
//     if (ans.empty()) cout << -1 << endl;
//     else {
//         cout << ans.size() << endl;
//         for (auto ele : ans) {
//             cout << ele.first << " " << ele.second << endl;
//         }
//     }
// }

// int32_t main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         solve_testcase();
//     }
// }


// variation of min jumps problem, spent too much time on this, don't have morale rn, to continue, so copying code, and moving on.
#include<bits/stdc++.h>
#define len(s) (int)s.size()
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;
int ans = 0;
bool ok = true;

void Find(int a, int b, string& t, vector<string>& str, vector<pair<int, int>>& match) {
    int Max = 0, id = -1, pos = -1;
    for (int i = a; i <= b; i++) {
        for (int j = 0; j < len(str); j++) {
            string s = str[j];
            if (i + len(s) > len(t) || i + len(s) <= b) continue;
            if (t.substr(i, len(s)) == s) {
                if (i + len(s) > Max) {
                    Max = i + len(s);
                    id = j;
                    pos = i;
                }
            }
        }
    }
    if (id == -1) {
        ok = false;
        return;
    }
    else {
        match.emplace_back(id, pos);
        ans++;
        if (Max == len(t)) return;
        else Find(max(pos + 1, b + 1), Max, t, str, match);
    }
}


void solve() {
    ans = 0;
    ok = true;

    string t;
    cin >> t;
    int n;
    cin >> n;

    vector<string>s(n);
    vector<pair<int, int>>match;

    forn(i, n) {
        cin >> s[i];
    }

    Find(0, 0, t, s, match);
    if (!ok) cout << "-1\n";
    else {
        cout << ans << endl;
        for (auto& p : match) cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }

}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}