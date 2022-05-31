#include <bits/stdc++.h>

typedef long long num;
typedef long double numd;

#define MOD 1000000007

using namespace std;

int main() {
    num t;
    cin >> t;
    while (t--) {
        num n;
        cin >> n;
        num arr[n];
        for (num i = 0; i < n; i++) cin >> arr[i];

        map<num, num> m;
        for (num i = 0; i < n; i++) m[arr[i]]++;

        num max_frequency = max_element(m.begin(), m.end(), [](pair<num, num> a, pair<num, num> b) {
                                return a.second < b.second;
                            })->second;

        num n_remaining_elements = n - max_frequency;
        num total_operations = 0, current_step = 0;
        while (n_remaining_elements > 0) {
            total_operations += 1;                                                                     // clone
            total_operations += min(num(max_frequency * pow(2, current_step)), n_remaining_elements);  // exchange
            n_remaining_elements -= min(num(max_frequency * pow(2, current_step)), n_remaining_elements);
            current_step++;
        }

        cout << total_operations << endl;
    }
}

// correct