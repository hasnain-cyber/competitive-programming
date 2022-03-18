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
    num n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    num length = s.size();

    string answer_string = "";
    while (t--) {
        for (num i = 0; i < length; i++) {
            if (i != length - 1 && s[i] == 'B' && s[i + 1] == 'G') {
                answer_string += 'G';
                answer_string += 'B';
                i++;
            } else {
                answer_string += s[i];
            }
        }
        s = answer_string;
        answer_string = "";
    }
    cout << s << endl;
}

// correct