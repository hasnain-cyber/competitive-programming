#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    string s;
    cin >> s;

    string answer_string = "";
    for (num i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            answer_string += s[i];
            answer_string += s[i + 1];
            i += 1;
        }
    }
    cout << s.size() - answer_string.size() << endl;
    cout << answer_string << endl;
}

// correct