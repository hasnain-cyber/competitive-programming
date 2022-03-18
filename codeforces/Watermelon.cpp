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

    if (n / (double)2 == n / 2 && n / 2 >= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// correct