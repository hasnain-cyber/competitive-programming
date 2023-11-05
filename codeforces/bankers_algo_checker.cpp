#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<int>> allocations = {
        {1, 3, 1},
        {3, 2, 2},
        {0, 0, 0},
        {3, 1, 1},
        {0, 0, 2},
    };

    vector<vector<int>> max_allocations = {
        {4, 8, 3},
        {5, 3, 3},
        {7, 4, 3},
        {4, 2, 3},
        {3, 2, 4},
    };

    vector<int> max_available = { 10, 8, 7 };

    int n = allocations.size(); // no. of processes
    int m = allocations[0].size(); // no. of resources

    // vector<int> order = { 1, 4, 3, 2, 0 };
    // vector<int> order = { 1, 3, 0, 4, 2 };
    vector<int> order = { 1, 3, 4, 2, 0};
    // vector<int> order = { 4, 1, 3, 2, 0 };
    
    // check if the order is safe
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max_allocations[i][j] - allocations[i][j];
        }
    }

    vector<int> available = max_available;
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            available[i] -= allocations[j][i];
        }
    }

    for (int curr_process : order) {
        // print needs and available
        cout << "Process: " << curr_process << endl;
        cout << "Need: ";
        for (int i = 0; i < m; i++) {
            cout << need[curr_process][i] << " ";
        }
        cout << endl;
        cout << "Available: ";
        for (int i = 0; i < m; i++) {
            cout << available[i] << " ";
        }
        cout << endl;
        cout << endl;

        bool is_safe = true;
        for (int i = 0; i < m; i++) {
            if (need[curr_process][i] > available[i]) {
                is_safe = false;
                break;
            }
        }

        if (is_safe) {
            for (int i = 0; i < m; i++) {
                available[i] += allocations[curr_process][i];
            }
        } else {
            cout << "Unsafe" << endl;
            return 0;
        }
    }

    cout << "Safe" << endl;
}