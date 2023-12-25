#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }

    vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        deg[arr[i]]++;
        deg[i]--;
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    int i = 0, j = 0;
    int counter = 0;
    while (i < n && j < n) {
        while (i < n && deg[i] <= 0) i++;
        while (j < n && deg[j] >= 0) j++;

        if (i < n && j < n) {
            counter++;
            int giver = mp[i].back();
            mp[i].pop_back();
            if (giver == j) {
                giver = mp[i].back();
                mp[i].pop_back();
                mp[i].push_back(j);
            }
            deg[i]--;
            mp[j].push_back(giver);
            deg[j]++;
        }
    }

    vector<int> ans(n);
    for (auto it : mp) {
        for (auto giver : it.second) {
            ans[giver] = it.first + 1;
        }
    }

    cout << n - counter << endl;
    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}