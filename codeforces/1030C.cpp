#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

bool solve(string s, num check_sum, num counter) {
    if (s.size() == 0)
        return (counter > 1);

    num sum = 0;
    for (num i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
        if (check_sum == sum) {
            while (i + 1 < s.size() && s[i + 1] == '0')
                i++;
            return solve(s.substr(i + 1), check_sum, counter + 1);
        }
    }
    return false;
}

int main() {
    num n;
    cin >> n;
    string s;
    cin >> s;
    num index = 0;
    for (num i = 0; i < n; i++) {
        if (s[i] == '0')
            index++;
        else
            break;
    }
    s = s.substr(index);
    n = s.size();

    num sum = 0;
    bool flag = false;
    for (num i = 0; i < n; i++) {
        sum += s[i] - '0';
        if (solve(s, sum, 0)) {
            flag = true;
            break;
        }
    }
    if (flag || n == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// correct