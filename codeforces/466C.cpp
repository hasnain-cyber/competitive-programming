#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++)
        cin >> arr[i];

    num s = 0;
    s = accumulate(arr, arr + n, s);  // sum of all elements in arr
    if (s % 3 == 0) {
        num s1 = s / 3;
        num s2 = s1 * 2;
        num counter1 = 0, counter2 = 0, s = 0;
        for (num i = 0; i < n - 1; i++) {
            s += arr[i];
            if (s == s2)
                counter2 += counter1;
            if (s == s1)
                counter1++;
        }
        cout << counter2 << endl;

    } else {
        cout << 0 << endl;
    }
}

// correct