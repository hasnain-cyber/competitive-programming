#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num a, b, n;
    cin >> a >> b >> n;

    string answer_string;
    if (a % b == 0) {
        answer_string = to_string(a);
        for (num i = 0; i < n; i++)
            answer_string += '0';
        cout << answer_string << endl;
    } else {
        num temp_digit = -1;
        for (num i = 0; i < 10; i++) {
            num temp_num = stoi(to_string(a) + to_string(i));

            if (temp_num % b == 0) {
                temp_digit = i;
                break;
            }
        }
        if (temp_digit != -1) {
            answer_string = to_string(a);
            answer_string += to_string(temp_digit);
            for (num i = 0; i < n - 1; i++)
                answer_string += '0';
            cout << answer_string << endl;
        } else
            cout << -1 << endl;
    }
}

// correct