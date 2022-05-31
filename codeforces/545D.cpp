#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    num s = 0, counter = 0;
    for (num i = 0; i < n; i++) {
        if (s > arr[i]) {
            counter++;
            continue;
        }
        s += arr[i];
    }
    cout << n - counter << endl;
}

// correct