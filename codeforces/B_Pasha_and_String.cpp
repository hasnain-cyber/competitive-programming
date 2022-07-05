#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();

    int m;
    cin >> m;

    vector<int> flips(n / 2 + 1, 0);
    while (m--) {
        int index;
        cin >> index;
        flips[index] = (flips[index] + 1) % 2;
    }

    int running_sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        running_sum += flips[i];
        if (running_sum & 1) swap(s[i - 1], s[n - i]);
    }

    cout << s << endl;
}