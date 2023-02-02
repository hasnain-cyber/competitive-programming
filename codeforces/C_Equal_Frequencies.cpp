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
    string s;
    cin >> s;

    vector<char> ans;
    int min_cost = infinity;
    for (int k = 1; k <= 26; k++) {
        if (n % k) {
            continue;
        }

        vector<char> temp_ans(n);
        // declare freq map, having freuencies in ascending order
        map<char, int> freq;
        int cost = 0, required_count = n / k;
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (freq[s[i]] > required_count) {
                freq[s[i]]--;
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }
                cost++;
                temp_ans[i] = '?';
            } else {
                temp_ans[i] = s[i];
            }
        }

        map<char, int> erased_count;
        while (freq.size() > k) {
            auto it = freq.begin();
            char c = it->first;
            int count = it->second;
            freq.erase(it);
            erased_count[c] = count;
        }

        for (int i = 0; i < n; i++) {
            if (erased_count[temp_ans[i]]) {
                erased_count[temp_ans[i]]--;
                temp_ans[i] = '?';
                cost++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (temp_ans[i] == '?') {
                auto it = freq.begin();
                temp_ans[i] = it->first;
                it->second++;
            }
        }

        if (cost < min_cost) {
            min_cost = cost;
            ans = temp_ans;
        }
    }

    cout << min_cost << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
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