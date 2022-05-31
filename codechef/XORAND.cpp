#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;
        num arr[n];
        for (num i = 0; i < n; i++)
            cin >> arr[i];

        map<num, num> highest_set_bit_map;
        for (num i = 0; i < n; i++) {
            num highest_set_bit = floor(log2(arr[i]));
            highest_set_bit_map[highest_set_bit]++;
        }

        num ans = 0;
        for (auto it = highest_set_bit_map.begin(); it != highest_set_bit_map.end(); it++) {
            ans += (it->second * (it->second - 1)) / 2;
        }
        cout << ans << endl;
    }
}

// correct