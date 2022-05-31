#include <iostream>

typedef int i16;
typedef unsigned int u16;
typedef long int i32;
typedef unsigned long int u32;
typedef long long int i64;
typedef unsigned long long int u64;

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;

        int n = 5;

        string answer_string = "";
        for (int i = 0; i < 5; i++) {
            if (s[i] == t[i]) {
                answer_string += "G";
            } else {
                answer_string += "B";
            }
        }
        cout << answer_string << '\n';
    }
}

// correct