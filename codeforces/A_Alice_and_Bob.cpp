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

int list_gcd(vector<int> &arr) {
    int n = arr.size();

    int ans = arr[0];
    for (int i = 1; i < n; i++) {
        ans = __gcd(ans, arr[i]);
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int d = list_gcd(arr);
    int m = *max_element(arr.begin(), arr.end());

    int value = m / d - n;
    if (value & 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
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