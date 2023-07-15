#include <bits/stdc++.h>

// #define MOD 1000000007
#define MOD 998244353
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

int find_max_length(int l, int r) {
    return log2(r / l) + 1;
}

void solve_testcase() {
    int l, r;
    cin >> l >> r;

    int max_length = find_max_length(l, r);
    int ans = 0;

    // find largest value which still has max_length
    int low = l, high = r, largest_value = l;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (find_max_length(mid, r) == max_length) {
            largest_value = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // the one constructed by multiplying 2 repetedly
    ans = (ans + (largest_value - l + 1)) % MOD;

    // find the largest value for which a 3 instead of 2 will work, it may happen that even l is not able to afford that, so largest_value will be -1 intially, and will check that before adding to the ans.
    low = l, high = r, largest_value = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int new_value = (mid * (1 << (max_length - 1)) * 3) / 2;
        if (new_value <= r) {
            largest_value = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (largest_value != -1) {
        ans = (ans + (max_length - 1) * (largest_value - l + 1)) % MOD;
    }

    cout << max_length << ' ' << ans << endl;
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