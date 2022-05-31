#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;
        map<num, num> index_map;
        for (num i = 0; i < n; i++) {
            num value;
            cin >> value;
            index_map[value] = i;
        }

        string answer_string = "";
        num l = n, r = 0;
        for (num k = 1; k <= n; k++) {
            l = min(l, index_map[k]);
            r = max(r, index_map[k]);
            if (r - l + 1 == k)
                answer_string += '1';
            else
                answer_string += '0';
        }
        cout << answer_string << endl;
    }
}

// correct