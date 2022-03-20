#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n, k;
    cin >> n >> k;
    num arr[n];
    for (num i = 0; i < n; i++) cin >> arr[i];

    pair<num, num> answer_arr[n];
    for (num i = 0; i < n; i++) answer_arr[i] = pair<num, num>(i, arr[i]);
    sort(answer_arr, answer_arr + n,
         [](pair<num, num> a, pair<num, num> b) { return a.second < b.second; });

    cout << answer_arr[n - k].second << endl;
    for (num i = n - k; i < n; i++) cout << answer_arr[i].first + 1 << " ";

    return 0;
}

// runtime error, don't know why