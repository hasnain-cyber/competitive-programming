#include <bits/stdc++.h>

using namespace std;

int main() {
    // vector<int> layers = { 5, 8, 1 };
    // vector<int> energy = { 4, 2, 1 };
    // int k = 10;

    vector<int> layers = { 2, 2, 5 };
    vector<int> energy = { 2, 3, 1};
    int k = 5;

    int n = layers.size();
    
    int prev_end = 0, prev_energy = k;
    for (int i = 0; i < n; i++) {
        int curr_energy = prev_energy + (i > 0 ? 0 : layers[i - 1]);
        prev_end = max(prev_end, i);

        int curr_end = prev_end;
        while (curr_end < n && curr_energy - layers[curr_end] >= energy[curr_end]) {
            curr_energy -= layers[curr_end];
            curr_end++;
        }

        int dist = (curr_end - 1) - i + 1;
        cout << dist << " ";
    }
    cout << endl;
}