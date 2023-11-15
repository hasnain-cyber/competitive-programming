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

vector<int> find_max(vector<int>& arr) {
    int n = arr.size();

    int curr_l = 0, curr_sum = 1;
    int max_sum = 1, max_l = 0, max_r = -1;
    for (int i = 0; i < n - 1; i++) {
        curr_sum += arr[i] - arr[i + 1] + 2;
        if (curr_sum < 1) {
            curr_l = i + 1;
            curr_sum = 1;
        }
        if (curr_sum > max_sum) {
            max_l = curr_l, max_r = i;
            max_sum = curr_sum;
        }
    }

    return { max_sum, arr[max_l], arr[max_r + 1] };
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    int l = 0, r = 0, a = arr[0], curr_max = 1;
    for (auto it : mp) {
        vector<int> temp = find_max(it.second);

        if (curr_max < temp[0]) {
            l = temp[1], r = temp[2], a = it.first;
            curr_max = temp[0];
        }
    }

    cout << a << " " << l + 1 << " " << r + 1 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}