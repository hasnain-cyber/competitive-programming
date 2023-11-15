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

int calculate_max(vector<pair<int, int>>& arr) {
    int n = arr.size();

    vector<int> starts, ends;
    for (int i = 0; i < n; i++) {
        starts.push_back(arr[i].first);
        ends.push_back(arr[i].second + 1);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int counter = 0, ans = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (starts[i] < ends[j]) {
            counter++, i++;
        }
        else if (starts[i] > ends[j]) {
            counter--, j++;
        }
        else {
            i++, j++;
        }

        ans = max(ans, counter);
    }

    return ans;
}

void solve_testcase() {
    int q, n;
    cin >> q >> n;
    vector<pair<int, int>> arr(q);
    for (int i = 0; i < q; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        arr[i].second--;
    }

    int ans = 0;

    // min value at 0
    vector<pair<int, int>> temp;
    for (int i = 0; i < q; i++) {
        if (arr[i].first > 0) temp.push_back(arr[i]);
    }

    ans = max(ans, calculate_max(temp));

    temp.clear();
    for (int i = 0; i < q; i++) {
        if (arr[i].second < n - 1) temp.push_back(arr[i]);
    }

    ans = max(ans, calculate_max(temp));

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}