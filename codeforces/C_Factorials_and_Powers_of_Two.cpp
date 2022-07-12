#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> &arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> &arr) {
    sort(arr.begin(), arr.end());
}

int set_bits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += (n & 1);
        n >>= 1;
    }

    return ans;
}

int solve(vector<int> &factorials, int i, int n, int value) {
    if (i == n) return set_bits(value);

    if (factorials[i] <= value) {
        return min(1 + solve(factorials, i + 1, n, value - factorials[i]), solve(factorials, i + 1, n, value));
    } else {
        return set_bits(value);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = pow(10, 12);
    vector<int> factorials;
    int value = 6;
    int i = 4;
    while (value <= N) {
        factorials.push_back(value);
        value *= i;
        i++;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << solve(factorials, 0, factorials.size(), n) << endl;
    }
}