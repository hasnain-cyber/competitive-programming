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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) st.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            if (s >= x && (s & 1) == (x & 1)) {
                cout << "YES" << endl;
            }
            else {
                if (st.empty()) {
                    cout << "NO" << endl;
                    continue;
                }

                int first = *st.begin(), last = *st.rbegin();
                int s1 = s - 2 * first - 1;
                int s2 = s - 2 * (n - last - 1) - 1;
                int value = max(s1, s2);

                if (value >= x && (value & 1) == (x & 1)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else {
            int i, v;
            cin >> i >> v;
            i--;

            s -= arr[i];
            s += v;

            if (arr[i] == 1) st.erase(i);
            if (v == 1) st.insert(i);

            arr[i] = v;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}