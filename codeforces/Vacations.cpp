#include <math.h>

#include <iostream>
#include <vector>

typedef int i16;
typedef long int i32;
typedef long long int i64;

using namespace std;

i64 solve(i64 counter, i64 index, i64 n, i64 arr[], bool free_for_contest, bool free_for_gym) {
    if (index == n) return counter;

    switch (arr[index]) {
        case (0):
            return solve(counter + 1, index + 1, n, arr, true, true);
        case (1):
            if (free_for_contest)
                return solve(counter, index + 1, n, arr, false, true);
            else
                return solve(counter + 1, index + 1, n, arr, true, true);
        case (2):
            if (free_for_gym)
                return solve(counter, index + 1, n, arr, true, false);
            else
                return solve(counter + 1, index + 1, n, arr, true, true);
        default:
            if (free_for_contest && !free_for_gym)
                return solve(counter, index + 1, n, arr, false, true);
            else if (free_for_gym && !free_for_contest)
                return solve(counter, index + 1, n, arr, true, false);
            else
                return min(
                    solve(counter, index + 1, n, arr, false, true),
                    solve(counter, index + 1, n, arr, true, false));
    }
}

int main() {
    i64 n;
    cin >> n;

    i64 arr[n];
    for (i64 i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(0, 0, n, arr, true, true) << endl;
}

// tle