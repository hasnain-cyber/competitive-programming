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
    string s1, s2;
    cin >> s1 >> s2;
    int block_time, n_queries;
    cin >> block_time >> n_queries;

    int n = s1.length();
    vector<bool> blocked = vector<bool>(n + 1, false);
    int n_bad_positions = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            n_bad_positions++;
        }
    }

    int current_time = 0;
    queue<pair<int, int>> block_queue;
    for (int t = 1; t <= n_queries; t++) {
        int query_type;
        cin >> query_type;

        current_time++;
        // cout << "current_time: " << current_time << endl;
        // cout << "blocked positions: ";
        // print_arr(blocked);

        // clear the blocked characters before each query
        while (!block_queue.empty() && block_queue.front().second <= current_time) {
            int position = block_queue.front().first;

            blocked[position] = false;
            block_queue.pop();

            if (s1[position - 1] != s2[position - 1]) {
                n_bad_positions++;
            }
        }

        if (query_type == 1) {
            int position;
            cin >> position;

            blocked[position] = true;
            block_queue.push({position, current_time + block_time});
            if (s1[position - 1] != s2[position - 1]) {
                n_bad_positions--;
            }
        } else if (query_type == 2) {
            int string_index_1, position_1, string_index_2, position_2;
            cin >> string_index_1 >> position_1 >> string_index_2 >> position_2;

            bool was_position_1_bad = s1[position_1 - 1] != s2[position_1 - 1];
            bool was_position_2_bad = s1[position_2 - 1] != s2[position_2 - 1];

            // swap the characters
            if (string_index_1 == 1 && string_index_2 == 1) {
                swap(s1[position_1 - 1], s1[position_2 - 1]);
            } else if (string_index_1 == 1 && string_index_2 == 2) {
                swap(s1[position_1 - 1], s2[position_2 - 1]);
            } else if (string_index_1 == 2 && string_index_2 == 1) {
                swap(s2[position_1 - 1], s1[position_2 - 1]);
            } else if (string_index_1 == 2 && string_index_2 == 2) {
                swap(s2[position_1 - 1], s2[position_2 - 1]);
            }

            // check if the characters at the changed positions are affected
            if (was_position_1_bad) {
                if (s1[position_1 - 1] == s2[position_1 - 1]) {
                    n_bad_positions--;
                }
            } else {
                if (s1[position_1 - 1] != s2[position_1 - 1]) {
                    n_bad_positions++;
                }
            }

            if (was_position_2_bad) {
                if (s1[position_2 - 1] == s2[position_2 - 1]) {
                    n_bad_positions--;
                }
            } else {
                if (s1[position_2 - 1] != s2[position_2 - 1]) {
                    n_bad_positions++;
                }
            }
        } else {
            if (n_bad_positions == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        // cout << "query #: " << t << endl;
        // cout << "query_type: " << query_type << endl;
        // cout << "s1: " << s1 << " s2: " << s2 << endl;
        // cout << "n_bad_positions: " << n_bad_positions << endl;
        // cout << "blocked: ";
        // print_arr(blocked);
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