#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    string n;
    cin >> n;
    num length = n.size();

    bool flag = false;
    for (num i = 0; i < length; i++) {
        num digit = n[i] - '0';
        if (digit % 2 == 0) {
            flag = true;
            break;
        }
    }
    if (flag) {
        num smaller_even_index = -1;
        for (num i = 0; i < length; i++) {
            num compare_digit = n[i] - '0';
            if ((compare_digit < n[length - 1] - '0') && (compare_digit % 2 == 0)) {
                smaller_even_index = i;
                break;
            }
        }

        if (smaller_even_index == -1) {
            num larger_even_index = -1;
            for (num i = length - 2; i >= 0; i--) {
                num compare_digit = n[i] - '0';
                if (compare_digit % 2 == 0) {
                    larger_even_index = i;
                    break;
                }
            }
            swap(n[length - 1], n[larger_even_index]);
        } else {
            swap(n[length - 1], n[smaller_even_index]);
        }

        cout << n << endl;
    } else {
        cout << -1 << endl;
    }
}

// correct