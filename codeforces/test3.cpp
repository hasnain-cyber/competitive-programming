#include <bits/stdc++.h>

using namespace std;

string solve(int n, string s, int k) {
    for (int i = 0; i < n; i++) {
        if (k <= 0) continue;

        if (i == 0) {
            if (s[i] == '1') continue;
            else {
                s[i] = '1';
                k--;
            }
        }
        else {
            if (s[i] == '0') continue;
            else {
                s[i] = '0';
                k--;
            }
        }
    }

    return s;
}

int main() {
    int n, k;
    string l;
    cin >> n >> l >> k;
    cout << solve(n, l, k) << endl;
}