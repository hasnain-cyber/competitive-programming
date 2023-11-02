#include <bits/stdc++.h>

using namespace std;

class UndirectedGraph {
    private:
        int n;
        vector<set<int>> graph;

        bool check(int curr, int dist, int max_dist, int v, vector<bool>& visited, set<int>& loudspeakers) {
            if (dist > max_dist) return false;
            if (curr == v) return true;
            visited[curr] = true;

            for (auto neighbour : graph[curr]) {
                if (visited[neighbour]) continue;

                if (loudspeakers.find(curr) != loudspeakers.end()) dist = 0;
                if (check(neighbour, dist + 1, max_dist, v, visited, loudspeakers)) return true;
            }

            return false;
        }

public:
    UndirectedGraph(int n1) {
        n = n1;
        graph = vector<set<int>>(n);
    }
    
    void add_edge(int u, int v) {
        graph[u].insert(v);
        graph[v].insert(u);
    }

    bool check(int u, int v, int max_dist, set<int>& loudspeakers) {
        vector<bool> visited(n, false);
        return check(u, 0, max_dist, v, visited, loudspeakers);
    }
};

int main() {
    // int n = 6;
    // vector<pair<int, int>> edges = {
    //     {1, 2},
    //     {2, 3},
    //     {3, 4},
    //     {4, 5},
    //     {5, 6}
    // };
    // set<int> loudspeakers = { 1, 3 };
    // int source = 1, destination = 6;

    int n = 5;
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {2, 4},
        {4, 5},
    };
    set<int> loudspeakers = { 2, 3, 4 };
    int source = 3, destination = 5;

    UndirectedGraph graph(n);
    for (auto edge : edges) {
        graph.add_edge(edge.first - 1, edge.second - 1);
    }

    set<int> loudspeakers2;
    for (auto ele : loudspeakers) loudspeakers2.insert(ele - 1);
    int low = 0, high = 1e9, ans = 1e9;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (graph.check(source - 1, destination - 1, mid, loudspeakers2)) {
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}