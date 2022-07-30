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
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string s;
    for (int i = 0; i < m; i++) {
        s.push_back('B');
    }

    for (int i = 0; i < n; i++) {
        int index1 = arr[i] - 1;
        int index2 = m - index1 - 1;

        if (index1 > index2) {
            swap(index1, index2);
        }

        if (s[index1] == 'B') {
            s[index1] = 'A';
        } else {
            s[index2] = 'A';
        }
    }

    cout << s << endl;
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