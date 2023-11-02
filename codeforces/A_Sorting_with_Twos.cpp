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

bool is_power_of_2(int n) {
    return (n & (n - 1)) == 0;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    int prev = 0;
    int curr = 1;
    while (curr <= n) {
        // from prev + 1 to curr, check if sorted
        bool sorted = true;
        for (int i = prev + 1; i < curr; i++) {
            if (arr[i] > arr[i + 1]) {
                sorted = false;
                break;
            }
        }

        if (!sorted) {
            cout << "NO" << endl;
            return;
        }

        prev = curr;
        curr *= 2;
    }

    curr /= 2;
    for (int i = curr + 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}