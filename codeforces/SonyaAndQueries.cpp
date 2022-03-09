#include <math.h>

#include <iostream>
#include <map>

using namespace std;

string convert_number_to_pattern(string n) {
    string answer = "";

    for (int i = 0; i < n.length(); i++) {
        int digit = int(n[i]);
        answer += to_string(digit % 2);
    }

    // remove leading zeros from answer
    while (answer[0] == '0') {
        answer = answer.substr(1);
    }
    return answer;
}

int main() {
    int t;
    cin >> t;

    map<string, int> temp_dict;
    for (int i = 0; i < t; i++) {
        char type;
        string value;
        cin >> type >> value;

        // remove leading zeros from value
        while (value[0] == '0') {
            value = value.substr(1);
        }

        if (type == '+') {
            temp_dict[convert_number_to_pattern(value)] += 1;
        } else if (type == '-') {
            temp_dict[convert_number_to_pattern(value)] -= 1;
        } else {
            cout << temp_dict[convert_number_to_pattern(value)] << endl;
        }
    }
}

// correct