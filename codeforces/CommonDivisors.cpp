#include <math.h>

#include <algorithm>
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
    for (i64 i = 0; i < n; i++)
        cin >> arr[i];

    i64 gcd = arr[0];
    for (i64 i = 1; i < n; i++)
        gcd = __gcd(gcd, arr[i]);

    map<i64, i64> mp;
    while (gcd % 2 == 0) {
        mp[2]++;
        gcd = gcd / 2;
    }
    for (int i = 3; i <= sqrt(gcd); i = i + 2) {
        while (gcd % i == 0) {
            mp[i]++;
            gcd = gcd / i;
        }
    }
    if (gcd > 2)
        mp[gcd]++;

    i64 ans = 1;
    for (auto element : mp)
        ans *= (element.second + 1);
    cout << ans << endl;
}

// correct