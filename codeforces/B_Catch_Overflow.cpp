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
    int upper_limit = pow(2, 32) - 1;

    int n;
    cin >> n;
    stack<pair<int, int>> command_stack;
    // command types
    // 0: for iterations
    // 1: add <number>
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command[0] == 'f') {
            int iterations;
            cin >> iterations;
            command_stack.push({0, iterations});
        } else if (command[0] == 'a') {
            command_stack.push({1, 1});
        } else {
            int sum = 0;
            while (command_stack.top().first == 1) {
                sum += command_stack.top().second;
                command_stack.pop();
            }
            int iterations = command_stack.top().second;
            command_stack.pop();
            if (iterations * sum > upper_limit) {
                cout << "OVERFLOW!!!" << endl;
                return;
            }
            command_stack.push({1, iterations * sum});
        }
    }
    int sum = 0;
    while (!command_stack.empty()) {
        sum += command_stack.top().second;
        if (sum > upper_limit) {
            cout << "OVERFLOW!!!" << endl;
            return;
        }
        command_stack.pop();
    }
    cout << sum << endl;
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