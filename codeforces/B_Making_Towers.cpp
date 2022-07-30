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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (mp[i].size() == 0) {
            ans.push_back(0);
        } else if (mp[i].size() == 1) {
            ans.push_back(1);
        } else {
            int curr = mp[i][0];
            int counter = 1;
            for (int k = 1; k < mp[i].size(); k++) {
                if ((mp[i][k] - curr) % 2 == 1) {
                    counter++;
                    curr = mp[i][k];
                }
            }

            ans.push_back(counter);
        }
    }

    print_arr(ans);
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