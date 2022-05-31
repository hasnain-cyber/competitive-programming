#include <algorithm>
#include <cmath>
#include <iostream>
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

    i64 q;
    cin >> q;
    for (i64 i = 0; i < q; i++) {
        i64 value;
        cin >> value;

        i64 index = lower_bound(arr, arr + n, value) - arr;
        if (arr[index] == value)
            cout << "Yes " << index + 1 << endl;
        else
            cout << "No " << index + 1 << endl;
    }
}

// correct