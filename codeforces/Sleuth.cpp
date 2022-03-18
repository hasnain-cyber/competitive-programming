#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <vector>

typedef long long int num;

using namespace std;

int main() {
    string question;
    getline(cin, question);
    num length = question.size();

    char last_character;
    for (num i = 0; i < length; i++) {
        num index = length - i - 1;
        if (question[index] != ' ' && question[index] != '?') {
            last_character = question[index];
            break;
        }
    }

    if (last_character == 'a' || last_character == 'e' || last_character == 'i' || last_character == 'o' || last_character == 'u' || last_character == 'y' || last_character == 'A' || last_character == 'E' || last_character == 'I' || last_character == 'O' || last_character == 'U' || last_character == 'Y')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// correct