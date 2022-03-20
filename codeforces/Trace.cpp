#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <vector>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    reverse(arr, arr + n);

    num ans = 0;
    for (num i = 0; i < n; i++) {
        if (i % 2 == 0)
            ans += pow(arr[i], 2);
        else
            ans -= pow(arr[i], 2);
    }

    cout << ans * 2 * acos(0.0) << endl;
}

// correct