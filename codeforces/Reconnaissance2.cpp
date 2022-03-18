#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

typedef int i16;
typedef long int i32;
typedef long long int i64;

using namespace std;

int main() {
    i64 n;
    cin >> n;
    i64 arr[n];
    for (i64 i = 0; i < n; i++) {
        cin >> arr[i];
    }

    i64 min_index = 0, min_difference = numeric_limits<i64>::max();
    for (i64 i = 0; i < n; i++) {
        i64 difference = abs(arr[i] - arr[(i + 1) % n]);
        if (difference < min_difference) {
            min_difference = difference;
            min_index = i;
        }
    }
    cout << min_index + 1 << " " << (min_index + 1) % n + 1 << endl;
}

// correct