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
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> segments;
    for (int i = 0; i < m; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        segments.insert(make_pair(temp.first - 1, temp.second - 1));
    }

    int q;
    cin >> q;
    vector<int> modified_indices(q);
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        modified_indices[i] = temp - 1;
    }

    int low = 0, high = q;
    int answer = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        vector<int> temp_arr(n, 0);
        // make the first mid queries.
        for (int i = 0; i < mid; i++) {
            temp_arr[modified_indices[i]] = 1;
        }

        // cout << "mid: " << mid << endl;
        // cout << "temp arr: " << endl;
        // print_arr(temp_arr);

        vector<int> prefix_sum = temp_arr;
        for (int i = 1; i < n; i++) {
            prefix_sum[i] += prefix_sum[i - 1];
        }

        // cout << "prefix sum: " << endl;
        // print_arr(prefix_sum);

        bool flag = false;
        for (auto segment : segments) {
            int segment_sum = prefix_sum[segment.second] - (segment.first >= 1 ? prefix_sum[segment.first - 1] : 0);
            int length = segment.second - segment.first + 1;

            // check if segment is beautiful, if yes, break
            // cout << segment.first << ' ' << segment.second << ' ' << segment_sum << ' ' << length << endl;
            if (segment_sum > length / 2) {
                flag = true;
                break;
            }
        }

        if (flag) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
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