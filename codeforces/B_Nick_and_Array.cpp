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

    int count_positives = 0, count_negatives = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            count_positives++;
        else
            count_negatives++;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) arr[i] = -arr[i] - 1;
    }

    if (n & 1) {
        int min_element = MAX;
        for (int i = 0; i < n; i++) min_element = min(min_element, arr[i]);

        for (int i = 0; i < n; i++) {
            if (arr[i] == min_element) {
                arr[i] = -arr[i] - 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}