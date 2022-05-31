#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

using namespace std;

int main() {
    num n;
    cin >> n;
    pair<num, num> arr[n];
    for (int i = 0; i < n; i++) {
        pair<num, num> p;
        cin >> p.first >> p.second;
        arr[i] = p;
    }
    sort(arr, arr + n);

    num previous_value = 0;
    for (num i = 0; i < n; i++) {
        if (arr[i].second >= previous_value)
            previous_value = arr[i].second;
        else
            previous_value = arr[i].first;
    }
    cout << previous_value << endl;
}

// correct