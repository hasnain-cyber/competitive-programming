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
    num d, n;
    cin >> d;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    num counter = 0;
    for (num i = 0; i < n - 1; i++) 
        counter += d - arr[i];

    cout << counter << endl;
}

// correct