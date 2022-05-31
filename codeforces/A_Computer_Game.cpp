#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool solve(string arr[], int i, int j, int n, set<pair<int, int>> &visited) {
    if (visited.find(make_pair(i, j)) != visited.end()) {
        return false;
    } else {
        visited.insert(make_pair(i, j));
    }

    if (i == 1 && j == n - 1) {
        return true;
    }

    int di[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dj[] = {1, -1, 0, 0, 1, -1, -1, 1};
    for (int k = 0; k < 8; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni >= 0 && ni < 2 && nj >= 0 && nj < n && arr[ni][nj] != '1') {
            if (solve(arr, ni, nj, n, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string arr[2];
        cin >> arr[0] >> arr[1];

        set<pair<int, int>> visited;
        cout << (solve(arr, 0, 0, n, visited) ? "YES" : "NO") << endl;
    }
}

// correct