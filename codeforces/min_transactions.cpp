#include <bits/stdc++.h>

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

int get_min(vector<int>& arr) {
    int n = arr.size();

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[ans] > arr[i]) ans = i;
    }
    return ans;
}

int get_max(vector<int>& arr) {
    int n = arr.size();

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[ans] < arr[i]) ans = i;
    }
    return ans;
}

int solve(vector<vector<int>>& arr, int m) {
    int n = arr.size();

    vector<int> flow(m, 0);
    for (auto it : arr) {
        flow[it[0]] -= it[2];
        flow[it[1]] += it[2];
    }

    int ans = 0;
    while (flow[get_min(flow)] != 0) {
        // print_arr(flow);

        int mn = get_min(flow);
        int mx = get_max(flow);
        int owe = min(-flow[mn], flow[mx]);

        flow[mx] -= owe;
        flow[mn] += owe;
        ans++;
    }

    return ans;
}

int main() {
    // vector<vector<int>> arr = {
    //     {0, 1, 20},
    //     {1, 0, 5},
    //     {1, 2, 10},
    //     {2, 0, 10},
    // };
    // int m = 3;

    vector<vector<int>> arr = {
        {0, 1, 10},
        {2, 0, 5},
    };
    int m = 3;

    cout << solve(arr, m) << endl;
}