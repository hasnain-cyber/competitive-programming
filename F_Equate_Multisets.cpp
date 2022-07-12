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
    for (T element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

vector<int> reduce_arr(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int current = arr[i];
        while (current % 2 == 0 && current > 0) {
            current = current / 2;
        }

        ans[i] = current;
    }

    return ans;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> reduced_a = reduce_arr(a);
    vector<int> reduced_b = reduce_arr(b);

    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        mp1[reduced_a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        mp2[reduced_b[i]]++;
    }

    bool flag = true;
    for (auto it : mp2) {
        int value = it.first;
        int counter = it.second;

        while (value > 0 && counter > 0) {
            if (mp1.count(value)) {
                int temp = min(mp1[value], counter);
                mp1[value] -= temp;
                counter -= temp;
            }
            value = value / 2;
        }

        if (counter > 0) {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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