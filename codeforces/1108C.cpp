#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    string s;
    cin >> s;

    string answer_string1;
    num counter1 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string1 += 'R';
        else if (i % 3 == 1)
            answer_string1 += 'G';
        else
            answer_string1 += 'B';

        if (s[i] != answer_string1[i])
            counter1++;
    }
    string answer_string2;
    num counter2 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string2 += 'B';
        else if (i % 3 == 1)
            answer_string2 += 'G';
        else
            answer_string2 += 'R';

        if (s[i] != answer_string2[i])
            counter2++;
    }
    string answer_string3;
    num counter3 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string3 += 'G';
        else if (i % 3 == 1)
            answer_string3 += 'B';
        else
            answer_string3 += 'R';

        if (s[i] != answer_string3[i])
            counter3++;
    }
    string answer_string4;
    num counter4 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string4 += 'B';
        else if (i % 3 == 1)
            answer_string4 += 'R';
        else
            answer_string4 += 'G';

        if (s[i] != answer_string4[i])
            counter4++;
    }
    string answer_string5;
    num counter5 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string5 += 'G';
        else if (i % 3 == 1)
            answer_string5 += 'R';
        else
            answer_string5 += 'B';

        if (s[i] != answer_string5[i])
            counter5++;
    }
    string answer_string6;
    num counter6 = 0;
    for (num i = 0; i < n; i++) {
        if (i % 3 == 0)
            answer_string6 += 'R';
        else if (i % 3 == 1)
            answer_string6 += 'B';
        else
            answer_string6 += 'G';

        if (s[i] != answer_string6[i])
            counter6++;
    }

    num min_counter = numeric_limits<num>::max();
    string final_answer;
    if (counter1 < min_counter) {
        min_counter = counter1;
        final_answer = answer_string1;
    }
    if (counter2 < min_counter) {
        min_counter = counter2;
        final_answer = answer_string2;
    }
    if (counter3 < min_counter) {
        min_counter = counter3;
        final_answer = answer_string3;
    }
    if (counter4 < min_counter) {
        min_counter = counter4;
        final_answer = answer_string4;
    }
    if (counter5 < min_counter) {
        min_counter = counter5;
        final_answer = answer_string5;
    }
    if (counter6 < min_counter) {
        min_counter = counter6;
        final_answer = answer_string6;
    }
    cout << min_counter << endl;
    cout << final_answer << endl;
}

// correct, but code could have been more concise, using arrays.