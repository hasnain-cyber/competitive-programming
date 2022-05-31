#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num n;
    cin >> n;
    num counter = 0;
    for (num i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command.find("++") != string::npos) {
            counter++;
        } else {
            counter--;
        }
    }
    cout << counter << endl;
}

// correct