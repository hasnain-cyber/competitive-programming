#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        map<char, num> m1, m2;
        for (char c : s1) {
            m1[c]++;
        }
        for (char c : s2) {
            m2[c]++;
        }

        bool flag = true;
        for (auto it : m2) {
            char test_character = it.first;
            num test_count = it.second;
            num count_to_remove = m1[test_character] - test_count;
            if (count_to_remove < 0) {
                flag = false;
                break;
            } else {
                num counter = 0;
                string temp_string = "";
                for (num i = 0; i < s1.size(); i++) {
                    if (counter > count_to_remove) {
                        temp_string += s1[i];
                    } else {
                        temp_string += s1[i];
                        if (s1[i] == test_character) {
                            counter++;
                        }
                    }
                }
                s1 = temp_string;
            }
        }
        cout << s1 << endl;

        // if (flag) {
        //     if (s1 == s2) {
        //         cout << "Yes" << endl;
        //     } else {
        //         cout << "No" << endl;
        //     }
        // } else {
        //     cout << "No" << endl;
        // }
    }
}

// could not solve