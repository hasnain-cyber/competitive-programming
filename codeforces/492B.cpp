#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n, l;
    cin >> n >> l;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    num max_distance = max(arr[0], l - arr[n - 1]) * 2;
    for (num i = 0; i < n - 1; i++)
        max_distance = max(max_distance, arr[i + 1] - arr[i]);

    cout.precision(20);
    cout << max_distance / 2.0 << endl;
}

// correct