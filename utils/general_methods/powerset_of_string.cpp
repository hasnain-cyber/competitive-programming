#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

void solve(string s, ll index, string current) {
    if (index == s.size()) {
        cout << current << endl;
        return;
    }

    solve(s, index + 1, current + s[index]);
    solve(s, index + 1, current);
}

int main() {
    solve("abc", 0, "");
}