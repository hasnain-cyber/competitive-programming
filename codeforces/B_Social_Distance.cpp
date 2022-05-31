#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n, m;
        cin >> n >> m;
        num s = 0, min_ele = numeric_limits<num>::max(), max_ele = numeric_limits<num>::min();
        for (num i = 0; i < n; i++) {
            num temp;
            cin >> temp;
            s += temp;
            min_ele = min(min_ele, temp);
            max_ele = max(max_ele, temp);
        }

        num min_required_chairs = n + s + max_ele - min_ele;

        if (min_required_chairs <= m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

// correct