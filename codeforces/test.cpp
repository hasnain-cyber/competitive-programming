#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10;
    for (int i = 1; i <= n; i++) {
        int num = pow(2, i + 2);
        int den = pow(i + 2, 2);

        cout << (num / (double)den) << endl;
    }
}