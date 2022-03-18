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
    string s;
    cin >> s;

    num count_four = 0, count_seven = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '4')
            count_four++;
        else if (s[i] == '7')
            count_seven++;
    }

    if (count_four == 0 && count_seven == 0)
        cout << -1 << endl;
    else if (count_four >= count_seven)
        cout << 4 << endl;
    else
        cout << 7 << endl;
}

// correct