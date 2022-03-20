#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    num current_height = 0;
    num ans = 0;
    for (num i = 0; i < n; i++) {
        num new_height = arr[i];
        ans += abs(new_height - current_height) + 2;
        current_height = new_height;
    }
    cout << ans - 1 << endl;
}

// correct