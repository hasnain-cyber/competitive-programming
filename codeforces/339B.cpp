#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n, m;
    cin >> n >> m;
    num arr[m];
    for (num i = 0; i < m; i++) cin >> arr[i];

    num ans = 0, current_position = 1;
    for (num i = 0; i < m; i++) {
        if (current_position <= arr[i])
            ans += arr[i] - current_position;
        else
            ans += n - current_position + arr[i];
        current_position = arr[i];
    }
    cout << ans << endl;
}

// correct