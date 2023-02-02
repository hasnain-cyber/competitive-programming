#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()
#define infinity_double numeric_limits<double>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T> &arr) {
    for (T element : arr) {
        cout << element << ' ';
    }
    cout << endl;
}

template <typename T>
void sort_arr(vector<T> &arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> current_hair(n);
    for (int i = 0; i < n; i++) {
        cin >> current_hair[i];
    }
    vector<int> desired_hair(n);
    for (int i = 0; i < n; i++) {
        cin >> desired_hair[i];
    }
    int m;
    cin >> m;
    map<int, int> razors;
    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        razors[value]++;
    }

    for (int i = 0; i < n; i++) {
        if (current_hair[i] < desired_hair[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    stack<int> monoStk;
    for (int i = 0; i < n; i++) {
        // first two cases for while using the razor
        while (!monoStk.empty() && monoStk.top() < desired_hair[i]) {
            monoStk.pop();
        }

        if (!monoStk.empty() && monoStk.top() == desired_hair[i]) {
            continue;
        }

        // suppose we don't even have to use the razor
        if (current_hair[i] == desired_hair[i]) {
            continue;
        }

        if (razors.find(desired_hair[i]) == razors.end()) {
            cout << "NO" << endl;
            return;
        } else {
            razors[desired_hair[i]]--;
            monoStk.push(desired_hair[i]);
            if (razors[desired_hair[i]] == 0) {
                razors.erase(desired_hair[i]);
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve_testcase();
    }
}