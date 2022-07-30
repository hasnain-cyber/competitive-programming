#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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

    if (n & 1) {
        int s = 0;
        for (int i = 1; i < n - 1; i += 2) {
            int cost = max(max(arr[i - 1], arr[i + 1]) + 1 - arr[i], (int)0);
            s += cost;
        }

        cout << s << endl;
    } else {
        vector<int> sum1, sum2;

        int s1 = 0;
        for (int i = 1; i < n - 1; i += 2) {
            int cost = max(max(arr[i - 1], arr[i + 1]) + 1 - arr[i], (int)0);
            s1 += cost;
            sum1.push_back(s1);
        }

        int s2 = 0;
        for (int i = 2; i < n - 1; i += 2) {
            int cost = max(max(arr[i - 1], arr[i + 1]) + 1 - arr[i], (int)0);
            s2 += cost;
            sum2.push_back(s2);
        }

        int min_cost = min(s1, s2);
        for (int i = 0; i < sum1.size() - 1; i++) {
            min_cost = min(min_cost, sum1[i] + (s2 - sum2[i]));
        }

        cout << min_cost << endl;

        // cout << "HERE" << endl;
        // print_arr(sum1);
        // print_arr(sum2);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}