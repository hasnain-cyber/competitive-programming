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

vector<pair<int, int>> solve1(vector<int> arr, int n, int mx, int mn) {
    // make everything positive
    vector<pair<int, int>> ans;
    while (arr[mx] + arr[mn] < 0) {
        arr[mx] += arr[mx];
        ans.push_back({ mx, mx });
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] += arr[mx];
            ans.push_back({ i, mx });
        }
    }

    for (int i = 1; i < n; i++) {
        ans.push_back({ i, i - 1 });
    }

    return ans;
}

vector<pair<int, int>> solve2(vector<int> arr, int n, int mx, int mn) {
    // make everything negative
    vector<pair<int, int>> ans;
    while (arr[mx] + arr[mn] > 0) {
        arr[mn] += arr[mn];
        ans.push_back({ mn, mn });
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            arr[i] += arr[mn];
            ans.push_back({ i, mn });
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        ans.push_back({ i, i + 1 });
    }

    return ans;
}

void print(vector<pair<int, int>>& arr) {
    for (auto ele : arr) {
        cout << ele.first + 1 << " " << ele.second + 1 << endl;
    }
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mn = 0, mx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[mx]) mx = i;
        if (arr[i] < arr[mn]) mn = i;
    }

    if (arr[mx] > 0) {
        vector<pair<int, int>> ans1 = solve1(arr, n, mx, mn);
        if (ans1.size() <= 31) {
            cout << ans1.size() << endl;
            print(ans1);
        }
        else {
            vector<pair<int, int>> ans2 = solve2(arr, n, mx, mn);
            cout << ans2.size() << endl;
            print(ans2);
        }
    }
    else {
        vector<pair<int, int>> ans2 = solve2(arr, n, mx, mn);
        cout << ans2.size() << endl;
        print(ans2);
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}