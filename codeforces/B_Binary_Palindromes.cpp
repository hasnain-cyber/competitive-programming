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
    int odd = 0, even_bad = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        if (temp.size() & 1)
            odd++;
        else if (count(temp.begin(), temp.end(), '0') % 2)
            even_bad++;
    }

    if (even_bad == 0 || odd != 0 || even_bad % 2 == 0)
        cout << n << endl;
    else
        cout << n - 1 << endl;
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