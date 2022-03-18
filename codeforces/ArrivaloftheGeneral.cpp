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
    for (num i = 0; i < n; i++)
        cin >> arr[i];

    num max_value = numeric_limits<num>::min(), max_value_index = -1;
    for (num i = 0; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
            max_value_index = i;
        }
    }

    num min_value = numeric_limits<num>::max(), min_value_index = -1;
    for (num i = 0; i < n; i++)
        min_value = min(min_value, arr[i]);
    for (num i = n - 1; i >= 0; i--) {
        if (arr[i] == min_value) {
            min_value_index = i;
            break;
        }
    }

    num ans = max_value_index + n - min_value_index - 1;
    if (max_value_index > min_value_index)
        ans -= 1;
    cout << ans << endl;
}

// correct