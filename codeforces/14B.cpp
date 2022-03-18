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
    num n, x;
    cin >> n >> x;
    num min_value = numeric_limits<num>::min(), max_value = numeric_limits<num>::max();

    for (num i = 0; i < n; i++) {
        num a, b;
        cin >> a >> b;
        if (a > b) {
            num temp = b;
            b = a;
            a = temp;
        }
        min_value = max(min_value, a);
        max_value = min(max_value, b);
    }

    if (min_value > max_value)
        cout << -1 << endl;
    else if (x >= min_value && x <= max_value)
        cout << 0 << endl;
    else if (x < min_value)
        cout << min_value - x << endl;
    else
        cout << x - max_value << endl;
}

// correct