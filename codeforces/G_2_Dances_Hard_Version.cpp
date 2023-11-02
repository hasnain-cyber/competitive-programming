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

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> a_copy = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int low = 0, high = n, min_operations = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        vector<int> new_a, new_b;
        for (int i = 0; i < n - mid; i++) new_a.push_back(a[i]);
        for (int i = mid; i < n; i++) new_b.push_back(b[i]);

        bool flag = true;
        for (int i = 0; i < n - mid; i++) {
            if (new_a[i] >= new_b[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            min_operations = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    int low2 = 1, high2 = m, pivot = -1;
    while (low2 <= high2) {
        int mid2 = low2 + (high2 - low2) / 2;

        a = a_copy;
        a[0] = mid2;
        sort(a.begin(), a.end());

        low = 0, high = n;
        int min_operations2 = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            vector<int> new_a, new_b;
            for (int i = 0; i < n - mid; i++) new_a.push_back(a[i]);
            for (int i = mid; i < n; i++) new_b.push_back(b[i]);

            bool flag = true;
            for (int i = 0; i < n - mid; i++) {
                if (new_a[i] >= new_b[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                min_operations2 = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (min_operations2 == min_operations + 1) {
            pivot = mid2;
            high2 = mid2 - 1;
        }
        else {
            low2 = mid2 + 1;
        }
    }

    if (pivot == -1) {
        cout << min_operations * m << endl;
    }
    else {
        cout << min_operations * (pivot - 1) + (min_operations + 1) * (m - pivot + 1) << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}