#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num m, s;
    cin >> m >> s;
    cout << "here";

    num min_sum = 1, max_sum = 9 * m;
    if (min_sum <= s && s <= max_sum) {
        string min_ans = "", max_ans = "";
        min_ans += to_string(s % 9);
        for (num i = 0; i < m - s / 9 - 1; i++)
            min_ans += "0";
        for (num i = 0; i < s / 9; i++)
            min_ans += "9";

        for (num i = 0; i < s / 9; i++)
            max_ans += "9";
        max_ans += to_string(s % 9);
        while (max_ans.size() != m)
            max_ans += "0";

        if (s <= 9)
            max_ans = min_ans;

        cout << min_ans << " " << max_ans << endl;
    } else {
        cout << "-1 -1";
    }
}

// problem with taking input with 1 9 case.