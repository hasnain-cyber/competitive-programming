#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

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

vector<bool> seive(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    return is_prime;
}

vector<bool> is_prime;

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    // all elements must be distinct
    if (s.size() < n) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (!is_prime[i]) {
            continue;
        }

        vector<int> counter_arr(i, 0);
        for (int j = 0; j < n; j++) {
            counter_arr[arr[j] % i]++;
        }
        int min_value = *min_element(counter_arr.begin(), counter_arr.end());
        if (min_value > 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    is_prime = seive(100 / 2);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}