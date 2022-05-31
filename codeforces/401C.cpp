#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n, m;
    cin >> n >> m;

    if (n - 1 <= m and m <= 2 * (n + 1)) {
        string answer_string = "";
        while (true) {
            if (n == 0) {
                for (num i = 0; i < m; i++)
                    answer_string += '1';
                break;
            }

            if (n < m) {
                answer_string += "110";
                m -= 2;
                n -= 1;
            } else if (n == m) {
                answer_string += "10";
                m -= 1;
                n -= 1;
            } else {
                for (num i = 0; i < n; i++)
                    answer_string += "10";
                answer_string += "1";

                m = 0;
                n = 0;
            }
        }
        cout << answer_string << endl;

    } else {
        cout << -1 << endl;
    }
}

// could not solve