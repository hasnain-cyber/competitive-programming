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
    int k, n;
    cin >> k >> n;

    vector<int> ans;
    for (int t = k; t >= 0; t--) {
        vector<int> temp;
        temp.push_back(1);
        int curr_diff = 2;
        while (temp.size() < k) {
            if (temp.size() < t) {
                temp.push_back(temp.back() + curr_diff);
                curr_diff++;
            } else {
                temp.push_back(temp.back() + 1);
            }
        }

        if (temp.back() <= n) {
            ans = temp;
            break;
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