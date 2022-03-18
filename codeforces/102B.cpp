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
    string number;
    cin >> number;

    num counter = 0;
    while (number.size() != 1) {
        int sum = 0;
        for (int i = 0; i < number.size(); i++) {
            sum += number[i] - '0';
        }
        counter += 1;
        number = to_string(sum);
    }

    cout << counter << endl;
}

// correct