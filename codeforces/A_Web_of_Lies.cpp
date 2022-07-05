#include <bits/stdc++.h>

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

#define int long long int
#define double long double

using namespace std;

void process_query1(map<int, set<int>> &mp, int u, int v, vector<int> &weaker, int &counter) {
    mp[u].insert(v);
    mp[v].insert(u);

    if (u < v) {
        weaker[v]++;
        // if newly added edge to u makes it lose it's power.
        if (weaker[u] + 1 == mp[u].size()) counter--;
    } else {
        weaker[u]++;
        if (weaker[v] + 1 == mp[v].size()) counter--;
    }
}

void process_query2(map<int, set<int>> &mp, int u, int v, vector<int> &weaker, int &counter) {
    mp[u].erase(v);
    mp[v].erase(u);

    if (u < v) {
        weaker[v]--;
        if (weaker[u] == mp[u].size()) counter++;
    } else {
        weaker[u]--;
        if (weaker[v] == mp[v].size()) counter++;
    }
}

int find_ans_value(map<int, set<int>> mp, int current, vector<bool> visited) {
    visited[current] = true;

    bool flag = true;
    for (int child : mp[current]) {
        if (child > current) {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int child : mp[current]) visited[child] = true;
        return 1;
    } else {
        int ans = 0;
        for (int child : mp[current]) ans += find_ans_value(mp, child, visited);
        return ans;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<int, set<int>> mp;
    while (m--) {
        int parent, child;
        cin >> parent >> child;

        mp[parent].insert(child);
        mp[child].insert(parent);
    }

    vector<int> weaker(n + 1, 0);
    for (auto it : mp) {
        int parent = it.first;
        for (int child : it.second) {
            if (child < parent) weaker[parent]++;
        }
    }

    int counter = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i].size() == weaker[i]) counter++;
    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int parent, child;
            cin >> parent >> child;
            process_query1(mp, parent, child, weaker, counter);
        } else if (type == 2) {
            int parent, child;
            cin >> parent >> child;
            process_query2(mp, parent, child, weaker, counter);
        } else {
            cout << counter << endl;
        }
    }
}