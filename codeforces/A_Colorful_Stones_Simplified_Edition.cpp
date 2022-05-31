#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    string s, instruction_s;
    cin >> s >> instruction_s;
    num current_position = 0;
    for (num i = 0; i < instruction_s.size(); i++) {
        if (instruction_s[i] == s[current_position]) {
            current_position++;
        }
    }
    cout << current_position + 1;
}

// correct