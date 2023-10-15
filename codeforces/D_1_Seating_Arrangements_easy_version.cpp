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

int merge(vector<int>& arr, int i, int j, vector<int>& temp_merge) {
    int mid = (i + j) / 2;
    int p = i;
    int i2 = i, j2 = mid + 1;

    int ans = 0;
    while (i2 <= mid && j2 <= j) {
        if (arr[i2] <= arr[j2]) {
            temp_merge[p] = arr[i2];
            i2++;
        }
        else {
            temp_merge[p] = arr[j2];
            j2++;
            ans += (mid + 1 - i2);
        }
        p++;
    }
    while (i2 <= mid) {
        temp_merge[p] = arr[i2];
        i2++;
        p++;
    }
    while (j2 <= j) {
        temp_merge[p] = arr[j2];
        j2++;
        p++;
    }

    for (int index = i; index <= j; index++) {
        arr[index] = temp_merge[index];
    }

    return ans;
}

int merge_sort(vector<int>& arr, int i, int j, vector<int>& temp_merge) {
    int ans = 0;

    if (i < j) {
        int mid = (i + j) / 2;

        ans += merge_sort(arr, i, mid, temp_merge);
        ans += merge_sort(arr, mid + 1, j, temp_merge);
        ans += merge(arr, i, j, temp_merge);
    }

    return ans;
}

int countInversions(vector<int>& arr) {
    int n = arr.size();

    vector<int> temp_merge(n);
    return merge_sort(arr, 0, n - 1, temp_merge);
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n * m; i++) {
        arr[i].second = (n * m - arr[i].second);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        sort(arr.begin() + (i * m), arr.begin() + (i * m + m));

        vector<int> temp(m);
        for (int j = 0; j < m; j++) temp[j] = arr[j + (i * m)].second;
        ans += countInversions(temp);
    }

    cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}