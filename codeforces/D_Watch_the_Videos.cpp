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

bool can(vector<int> &arr, int l, int r, int m) {
    int low = l, high = r;
    while (low < high) {
        if (arr[low] + arr[high] > m) {
            return false;
        }
        high--;
        // low++;
        if (low < high) {
            if (arr[low] + arr[high] > m) {
                return false;
            }
            low++;
            // high--;
        }
    }
    return true;
}

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort_arr(arr);

    int ans = 0;
    // it will take at least sigma ai time to download all videos
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }

    int low = 0, high = n -  1;
    int max_good_pairs = 0;
    while (low <= high) {
        int mid = (high + low) / 2;

        if (can(arr, 0, mid, m)) {
            low = mid + 1;
            max_good_pairs = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << ans + (n - max_good_pairs) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}