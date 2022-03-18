#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

typedef long long int num;

using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    if (string(s1.rbegin(), s1.rend()) == s2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// correct