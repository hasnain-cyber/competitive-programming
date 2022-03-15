#include <math.h>

#include <iostream>

typedef int i16;
typedef long int i32;
typedef long long int i64;

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        i64 arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = arr[0];
        for (int i = 1; i < n; i++) ans |= arr[i];
        cout << ans << endl;
    }
}

// correct