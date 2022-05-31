#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    pair<num, num> one_position;
    for (num i = 0; i < 5; i++) {
        for (num j = 0; j < 5; j++) {
            num temp;
            cin >> temp;
            if (temp == 1)
                one_position = make_pair(i, j);
        }
    }
    cout << abs(one_position.first - 2) + abs(one_position.second - 2);
}

// correct