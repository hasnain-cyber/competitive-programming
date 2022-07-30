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

    int counter_zeros = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            counter_zeros++;
        } else {
            s.insert(arr[i]);
        }
    }

    while (s.size() > 1) {
        multiset<int> temp;
        int generated_zeros = 0;
        auto end = s.end();
        end--;
        for (auto it = s.begin(); it != end; it++) {
            auto second = it;
            second++;

            if (*second - *it > 0) {
                temp.insert(*second - *it);
            } else {
                generated_zeros++;
            }
        }

        if (counter_zeros > 0) {
            temp.insert(*s.begin());
            counter_zeros--;
        }

        counter_zeros += generated_zeros;
        s = temp;
    }

    if (s.size() == 1) {
        cout << *s.begin() << endl;
    } else {
        cout << 0 << endl;
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