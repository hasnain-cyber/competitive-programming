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

vector<vector<int>> factors;

void solve_testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int ans = infinity;
    int i = 0, j = -1;
    vector<int> freq(m + 1);
    int counter = 0;
    while (j < n) {
        if (counter < m) {
            j++;
            if (j == n) continue;

            for (int factor : factors[arr[j]]) {
                if (factor > m) continue;

                if (++freq[factor] == 1) counter++;
            }
        }
        else {
            ans = min(ans, arr[j] - arr[i]);

            for (int factor : factors[arr[i]]) {
                if (factor > m) continue;

                if (--freq[factor] == 0) counter--;
            }
            i++;
        }
    }

    if (ans == infinity) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}

vector<int> get_factors(int n) {
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i) continue;

        int f1 = i, f2 = n / i;
        if (f1 == f2) ans.push_back(f1);
        else {
            ans.push_back(f1);
            ans.push_back(f2);
        }
    }
    sort(ans.begin(), ans.end());

    return ans;
}

int32_t main() {
    int M = 1e5 + 1;
    factors = vector<vector<int>>(M);
    for (int i = 1; i < M; i++) {
        factors[i] = get_factors(i);
    }

    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}