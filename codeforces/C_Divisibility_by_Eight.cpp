#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

bool is_divisible(string s) {
    int n = stoi(s);
    return n % 8 == 0;
}

void solve_testcase() {
    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;

        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                string current;
                current.push_back(s[i]);
                current.push_back(s[j]);
                current.push_back(s[k]);
                if (is_divisible(current)) {
                    cout << "YES" << endl;
                    cout << current << endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;

        for (int j = i + 1; j < n; j++) {
            string current;
            current.push_back(s[i]);
            current.push_back(s[j]);
            if (is_divisible(current)) {
                cout << "YES" << endl;
                cout << current << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        string current;
        current.push_back(s[i]);
        if (is_divisible(current)) {
            cout << "YES" << endl;
            cout << current << endl;
            return;
        }
    }

    cout << "NO" << endl;
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