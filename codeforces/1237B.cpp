#include <bits/stdc++.h>

typedef long long int num;

using namespace std;

int main() {
    num n;
    cin >> n;
    num a[n], b[n];
    for (num i = 0; i < n; i++) cin >> a[i];
    map<num, num> b_index_map;
    for (num i = 0; i < n; i++) {
        num value;
        cin >> value;
        b_index_map[value] = i;
    }

    num c[n];
    for (num i = 0; i < n; i++)
        c[i] = b_index_map[a[i]] + 1;

    num max_value = c[0];
    num counter = 0;
    for (num i = 1; i < n; i++) {
        if (c[i] < max_value)
            counter++;
        max_value = max(max_value, c[i]);
    }
    cout << counter << endl;
}

// correct