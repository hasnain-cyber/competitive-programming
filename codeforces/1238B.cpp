#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

num remove_duplicates(num arr[], num n) {
    if (n == 0 || n == 1)
        return n;

    num temp[n];
    num j = 0;
    for (num i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    temp[j++] = arr[n - 1];
    for (num i = 0; i < j; i++)
        arr[i] = temp[i];
    return j;
}

int main() {
    num q;
    cin >> q;
    while (q--) {
        num n, r;
        cin >> n >> r;
        num arr[n];
        for (num i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);

        n = remove_duplicates(arr, n);

        if (n == 1)
            cout << 1 << endl;
        else {
            num ans = n;
            for (num x = 0; x <= n - 1; x++) {
                if (arr[n - x - 1] - x * r <= 0) {
                    ans = x;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
}

// correct