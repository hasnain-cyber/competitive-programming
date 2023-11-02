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
    multiset<int> starts, ends;
    for (int i = 0; i < n; i++) {
        char type;
        int u, v;
        cin >> type >> u >> v;

        if (type == '+') {
            starts.insert(u);
            ends.insert(v);
        }
        else {
            starts.erase(starts.find(u));
            ends.erase(ends.find(v));
        }

        if (starts.size() <= 1) {
            cout << "NO" << endl;
            continue;
        }

        auto it = ends.begin();
        int lowest_end = (*it);
        
        it = starts.end();
        it--;
        int highest_start = (*it);

        if (lowest_end < highest_start) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int32_t main() {
    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}