#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n;
    cin >> n;
    num arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<num, num> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;

    num answer_arr[int(pow(10, 5)) + 1];
    answer_arr[0] = 0, answer_arr[1] = mp[1];
    for (num i = 2; i <= int(pow(10, 5)); i++)
        answer_arr[i] = max(answer_arr[i - 1], answer_arr[i - 2] + mp[i] * i);

    cout << answer_arr[int(pow(10, 5))] << endl;
}

// correct