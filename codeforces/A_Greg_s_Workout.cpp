#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    num counter1 = 0, counter2 = 0, counter3 = 0;
    num mode = 0;
    for (num i = 0; i < n; i++) {
        num temp = mode % 3;
        if (temp == 0) {
            counter1 += arr[i];
        } else if (temp == 1) {
            counter2 += arr[i];
        } else {
            counter3 += arr[i];
        }
        mode += 1;
    }

    num max_value = max(counter1, max(counter2, counter3));
    if (max_value == counter1)
        cout << "chest" << endl;
    else if (max_value == counter2)
        cout << "biceps" << endl;
    else
        cout << "back" << endl;
}

// correct