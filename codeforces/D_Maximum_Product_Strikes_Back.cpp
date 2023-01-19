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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> segments;
    pair<int, int> curr_segment = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (curr_segment.first != -1) {
                segments.push_back(curr_segment);
                curr_segment = {-1, -1};
            }
        } else {
            if (curr_segment.first == -1) {
                curr_segment.first = i;
            }
            curr_segment.second = i;
        }
    }
    if (curr_segment.first != -1) {
        segments.push_back(curr_segment);
        curr_segment = {-1, -1};
    }

    pair<int, int> included_subarr = {-1, -1};
    int max_value = 1;
    for (auto segment : segments) {
        int leftmost_negative = -1;
        int rightmost_negative = -1;
        int curr_value = 1;
        for (int i = segment.first; i <= segment.second; i++) {
            curr_value *= arr[i];
            if (arr[i] < 0) {
                if (leftmost_negative == -1) {
                    leftmost_negative = i;
                }
                rightmost_negative = i;
            }
        }

        if (curr_value < 0) {
            int value1 = 1, value2 = 1;
            for (int i = leftmost_negative + 1; i <= segment.second; i++) {
                value1 *= arr[i];
            }
            for (int i = segment.first; i <= rightmost_negative - 1; i++) {
                value2 *= arr[i];
            }
            if (value1 >= value2) {
                curr_value /= arr[leftmost_negative];
                segment.first = leftmost_negative + 1;
            } else {
                curr_value /= arr[rightmost_negative];
                segment.second = rightmost_negative - 1;
            }
        }

        if (segment.first <= segment.second) {
            if (curr_value > max_value) {
                max_value = curr_value;
                included_subarr = segment;
            }
        }
    }

    if (included_subarr.first == -1) {
        cout << n << " " << 0 << endl;
    } else {
        cout << included_subarr.first << " " << n - included_subarr.second - 1 << endl;
    }
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