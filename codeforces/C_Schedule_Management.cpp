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
    int n, m;
    cin >> m >> n;  // m: no of workers, n: no of tasks
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    int l = 0, h = 2 * n;
    while (l <= h) {
        int mid = (l + h) / 2;

        // check if m no of workers can complete n no of tasks in mid no of hours.
        int total_tasks_done = 0;
        for (int i = 1; i <= m; i++) {
            int profient_tasks = mp[i];
            int proficient_tasks_done = min(mid, profient_tasks);
            int proficient_tasks_left = profient_tasks - proficient_tasks_done;
            int non_proficient_tasks_done = (mid - proficient_tasks_done) / 2;

            total_tasks_done += proficient_tasks_done + non_proficient_tasks_done;
        }

        if (total_tasks_done >= n) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << l << endl;
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