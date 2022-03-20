#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    string s;
    cin >> s;

    num count_A = 0, count_I = 0;
    for (char c : s) {
        if (c == 'A')
            count_A++;
        else if (c == 'I')
            count_I++;
    }
    if (count_I == 0)
        cout << count_A << endl;
    else if (count_I == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

// correct