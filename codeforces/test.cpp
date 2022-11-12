#include <bits/stdc++.h>

using namespace std;

int mod;
int find_value(vector<int> &a, vector<int> &b, int n) {
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < n) {
        ans = (ans + (a[i] * b[j]) % mod) % mod;
        i++, j--;
    }

    return ans;
}

int main() {
    mod = pow(10, 9) + 7;

    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        vector<int> temp(m);
        for (int j = 0; j < m; j++) cin >> temp[j];

        sort(temp.begin(), temp.end());
        arr[i] = temp;
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = max(ans, find_value(arr[i], arr[j], n));
        }
    }

    cout << ans << endl;
}