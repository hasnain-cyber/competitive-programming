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

bool check_palin_map(map<char, int> &mp) {
    int counter = 0;
    for (auto it : mp) {
        if (it.second & 1) {
            counter++;
        }
    }

    return counter <= 1;
}

void solve_testcase() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n & 1) {
        map<char, int> m1, m2;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (i & 1) {
                m1[ch]++;
            } else {
                m2[ch]++;
            }
        }

        if (check_palin_map(m1) && check_palin_map(m2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        map<char, int> m1, m2;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (i & 1) {
                m1[ch]++;
            } else {
                m2[ch]++;
            }
        }

        if (m1 == m2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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