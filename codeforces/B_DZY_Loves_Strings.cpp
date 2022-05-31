#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    string s;
    cin >> s;
    num length = s.size();

    num k;
    cin >> k;

    num arr[26];
    for (num i = 0; i < 26; i++) cin >> arr[i];

    num total = 0;
    for (num i = 0; i < length; i++) {
        total += arr[s[i] - 'a'] * (i + 1);
    }

    num max_value = *max_element(arr, arr + 26);
    total += max_value * (k * length + k * (k + 1) / 2);
    cout << total << endl;
}

// correct