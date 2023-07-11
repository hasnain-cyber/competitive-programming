#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curr_or = 0;
    vector<int> ans;
    vector<bool> visited(n, false);
    for (int i = 0; i < 32; i++) {
        int max_index = -1;
        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                continue;
            }

            if ((max_index == -1) || (curr_or | arr[j]) > (curr_or | arr[max_index])) {
                max_index = j;
            }
        }
        if (max_index != -1) {
            ans.push_back(arr[max_index]);
            curr_or |= arr[max_index];
            visited[max_index] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans.push_back(arr[i]);
        }
    }

    print_arr(ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}