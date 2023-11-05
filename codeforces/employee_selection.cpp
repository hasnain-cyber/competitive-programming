#include <bits/stdc++.h>

using namespace std;

int main() {
    // vector<int> arr = { 10, 20, 10, 15, 5, 30, 20 };
    // int team_size = 2;
    // int k = 3;

    vector<int> arr = { 10, 20, 50, 60, 10, 20, 30 };
    int team_size = 3;
    int k = 3;

    int n = arr.size();

    priority_queue<pair<int, int>> pq1, pq2;
    set<int> removed_values;
    int i = 0, j = n - 1;
    for (int t = 0; t < n; t++) {
        pq1.push({ arr[i], i });
        i++;
    }
    for (int t = 0; t < n; t++) {
        pq2.push({ arr[j], j });
        j--;
    }

    int ans = 0, counter = 0;
    while (counter < team_size) {
        while (!pq1.empty() && removed_values.find(pq1.top().second) != removed_values.end()) {
            pq1.pop();
            if (i < n) {
                pq1.push({ arr[i], i });
                i++;
            }
        }
        while (!pq2.empty() && removed_values.find(pq2.top().second) != removed_values.end()) {
            pq2.pop();
            if (j >= 0) {
                pq2.push({ arr[j], j });
                j--;
            }
        }

        if (pq2.empty()) {
            ans += pq1.top().first;
            removed_values.insert(pq1.top().second);
            pq1.pop();
            if (i < n) {
                pq1.push({ arr[i], i });
                i++;
            }
        }
        else if (pq1.empty()) {
            ans += pq2.top().first;
            removed_values.insert(pq2.top().second);
            pq2.pop();
            if (j >= 0) {
                pq2.push({ arr[j], j });
                j--;
            }
        }
        else {
            if (pq1.top().first > pq2.top().first) {
                ans += pq1.top().first;
                removed_values.insert(pq1.top().second);
                pq1.pop();
                if (i < n) {
                    pq1.push({ arr[i], i });
                    i++;
                }
            }
            else {
                ans += pq2.top().first;
                removed_values.insert(pq2.top().second);
                pq2.pop();
                if (j >= 0) {
                    pq2.push({ arr[j], j });
                    j--;
                }
            }
        }

        counter++;
    }

    cout << ans << endl;
}