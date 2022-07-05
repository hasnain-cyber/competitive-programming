#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void print_arr(vector<int> arr) {
    for (int element : arr) cout << element << ' ';
    cout << endl;
}

void sort_arr(vector<int> arr) {
    sort(arr.begin(), arr.end());
}

void solve_testcase() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> first_type_indices, second_type_indices;
    for (int i = 0; i < n; i++) {
        if (s1[i] == 'a' && s2[i] == 'b') {
            first_type_indices.push_back(i);
        } else if (s1[i] == 'b' && s2[i] == 'a') {
            second_type_indices.push_back(i);
        }
    }

    if (first_type_indices.size() % 2 != second_type_indices.size() % 2) {
        cout << -1 << endl;
        return;
    }

    cout << first_type_indices.size() / 2 + second_type_indices.size() / 2 + (first_type_indices.size() % 2) * 2 << endl;
    if (first_type_indices.size() > 0) {
        for (int i = 0; i < first_type_indices.size() - 1; i += 2) {
            cout << first_type_indices[i] + 1 << " " << first_type_indices[i + 1] + 1 << endl;
        }
    }

    if (second_type_indices.size() > 0) {
        for (int i = 0; i < second_type_indices.size() - 1; i += 2) {
            cout << second_type_indices[i] + 1 << " " << second_type_indices[i + 1] + 1 << endl;
        }
    }

    if (first_type_indices.size() % 2 == 1) {
        cout << first_type_indices[first_type_indices.size() - 1] + 1 << " " << first_type_indices[first_type_indices.size() - 1] + 1 << endl;
        cout << first_type_indices[first_type_indices.size() - 1] + 1 << " " << second_type_indices[second_type_indices.size() - 1] + 1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}