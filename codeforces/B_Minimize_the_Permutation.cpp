#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int min_element_index = min_element(arr.begin() + i, arr.end()) - arr.begin();
        if (min_element_index == i) continue;

        for (int j = min_element_index - 1; j >= i; j--) swap(arr[j], arr[j + 1]);

        // since i will increment anyway by one
        i = min_element_index - 1;
    }

    for (int element : arr) cout << element << " ";
    cout << endl;
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