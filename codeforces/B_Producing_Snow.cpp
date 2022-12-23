#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
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
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    multiset<int> ms;
    int total_temp = 0;
    for (int i = 0; i < n; i++) {
        int melted_today = 0;

        ms.insert(arr1[i] + total_temp);
        while (!ms.empty() && *ms.begin() <= arr2[i] + total_temp) {
            melted_today += *ms.begin() - total_temp;
            ms.erase(ms.begin());
        }
        melted_today += arr2[i] * ms.size();
        total_temp += arr2[i];
        cout << melted_today << ' ';
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}