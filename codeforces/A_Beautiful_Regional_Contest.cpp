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

    vector<pair<int, int>> values;
    for (int i = 0; i < n; i++) {
        int size = values.size();
        if (size == 0) {
            values.push_back({arr[i], 1});
        } else {
            if (values.back().first == arr[i]) {
                values.back().second++;
            } else {
                values.push_back({arr[i], 1});
            }
        }
    }

    int g = 0, s = 0, b = 0;
    int size = values.size();
    // first assign gold medals.
    g += values[0].second;

    // now assign silvers such that they are greater than gold.
    int i = 1;
    while (i < size && s <= g) {
        s += values[i].second;
        i++;
    }

    while (i < size) {
        if ((g + s + b + values[i].second <= n / 2))
            b += values[i].second;
        else
            break;
        i++;
    }

    if ((g + s + b) <= n / 2 && (g >= 1 && s >= 1 && s > g && b >= 1 && b > g)) {
        cout << g << " " << s << " " << b << endl;
    } else {
        cout << "0 0 0" << endl;
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