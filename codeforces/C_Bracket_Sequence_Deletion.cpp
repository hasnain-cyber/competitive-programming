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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = 0;
    int counter = 0;
    while (i < n) {
        if (s[i] == '(' && i != n - 1) {
            counter++;
            i += 2;
        } else {
            int j = i + 1;
            while (j < n && s[j] == '(') j++;

            if (j == n) {
                break;
            } else {
                i = j + 1;
                counter++;
            }
        }
    }

    cout << counter << " " << n - i << endl;
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