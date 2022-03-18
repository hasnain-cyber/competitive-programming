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
    string s1, s2;
    cin >> s1;
    cin >> s2;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    num check_value = s1.compare(s2);
    if (check_value < 0)
        check_value = -1;
    else if (check_value > 0)
        check_value = 1;
    cout << check_value << endl;
}

// correct