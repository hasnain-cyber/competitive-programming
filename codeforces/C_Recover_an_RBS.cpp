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

bool check(vector<char> &arr) {
    stack<char> s;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == '(') {
            s.push('(');
        } else {
            if (s.empty()) {
                return false;
            } else {
                s.pop();
            }
        }
    }

    return s.empty();
}

void solve_testcase() {
    string arr;
    cin >> arr;
    int n = arr.size();

    if (n & 1) {
        cout << "NO" << endl;
        return;
    }

    stack<char> s;
    vector<char> s1(n);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == '(') {
            s.push('(');
            s1[i] = '(';
        } else if (arr[i] == ')') {
            if (s.empty()) {
                s1[i] = ')';
            } else {
                s.pop();
                s1[i] = ')';
            }
        } else {
            if (s.empty()) {
                s.push('(');
                s1[i] = '(';
            } else {
                s.pop();
                s1[i] = ')';
            }
        }
    }

    vector<char> s2(n);
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] == '(' && arr[j] == ')') {
            s2[i] = '(';
            s2[j] = ')';
        } else if (arr[i] == '(' && arr[j] == '?') {
            s2[i] = '(';
            s2[j] = ')';
        } else if (arr[i] == '?' && arr[j] == ')') {
            s2[i] = '(';
            s2[j] = ')';
        } else if (arr[i] == '?' && arr[j] == '?') {
            s2[i] = '(';
            s2[j] = ')';
        } else if (arr[i] == ')' && arr[j] == '(') {
            s2[i] = ')';
            s2[j] = '(';
        } else if (arr[i] == ')' && arr[j] == '?') {
            s2[i] = ')';
            s2[j] = '(';
        } else if (arr[i] == '?' && arr[j] == '(') {
            s2[i] = ')';
            s2[j] = '(';
        } else {
            s2[i] = arr[i];
            s2[j] = arr[j];
        }
        i++, j--;
    }

    bool flag1 = check(s1);
    bool flag2 = check(s2);
    if (flag1 && flag2) {
        if (s1 == s2) {
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
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