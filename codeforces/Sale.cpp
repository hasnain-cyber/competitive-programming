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
    num n, m;
    cin >> n >> m;
    num arr[n];
    for (num i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    num ans = 0, counter = 0;
    for (num i = 0; i < n; i++) {
        if (arr[i] < 0) {
            ans += arr[i];
            counter++;
            if (counter == m)
                break;
        } else
            break;
    }
    cout << -ans << endl;
}

// correct