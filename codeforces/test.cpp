#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned char ch = 0;
    int count = 0;
    while (++ch <= 255) {
        count++;
        cout << ch << " ";
    }

    printf("count = %d\n", count);
}