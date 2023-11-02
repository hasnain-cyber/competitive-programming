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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int counter_ones = 0;
    for (int i = 0; i < n; i++) {
        counter_ones += (s[i] - '0');
    }

    if (counter_ones != (n - counter_ones)) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    deque<char> dq;
    for (int i = 0; i < n; i++) dq.push_back(s[i]);
    int i = 0, j = n - 1;
    while (i < j) {
        if (dq.front() != dq.back()) {
            dq.pop_front();
            dq.pop_back();
            i++;
            j--;
        }
        else {
            if (dq.front() == '0') {
                dq.push_back('0');
                dq.push_back('1');
                ans.push_back(j + 1);
                j += 2;
            }
            else {
                dq.push_front('1');
                dq.push_front('0');
                if (i == 0) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(i);
                }
                j += 2;
            }
        }
    }

    cout << ans.size() << endl;
    print_arr(ans);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}