#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<pair<string, int>> arr;
    map<string, int> total_score_map;
    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;

        arr.push_back({name, score});
        total_score_map[name] += score;
    }

    int max_score = MIN;
    for (auto it : total_score_map) {
        max_score = max(max_score, it.second);
    }

    map<string, int> current_score;
    for (int i = 0; i < n; i++) {
        string name = arr[i].first;
        int score = arr[i].second;

        current_score[name] += score;
        if (current_score[name] >= max_score && total_score_map[name] == max_score) {
            cout << name << endl;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}