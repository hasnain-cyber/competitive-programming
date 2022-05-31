#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num n;
    cin >> n;
    pair<num, num> arr[n];
    for (int i = 0; i < n; i++) {
        num temp1, temp2;
        cin >> temp1 >> temp2;
        arr[i] = make_pair(temp1, temp2);
    }

    num counter = 0;
    for (num i = 0; i < n; i++) {
        for (num j = i + 1; j < n; j++) {
            if (arr[i].second == arr[j].first) {
                counter++;
            }
            if (arr[i].first == arr[j].second) {
                counter++;
            }
        }
    }
    cout << counter;
}

// correct