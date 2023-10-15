#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

template <typename T>
void print_arr(vector<T>& arr) {
    for (T element : arr)
        cout << element << ' ';
    cout << endl;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> curr;
    int ans_left = -1, ans_right = -1, ans_product = 1;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (curr.empty()) continue;
            int temp = 1;
            for (int j = 0; j < curr.size(); j++) temp *= curr[j];

            if (temp > 0) {
                if (temp > ans_product) {
                    ans_product = temp;
                    ans_left = start;
                    ans_right = i - 1;
                }
            }
            else {
                int new_start = start;
                int new_product1 = temp;
                while (arr[new_start] > 0) {
                    new_product1 /= arr[new_start];
                    new_start++;
                }
                new_product1 /= arr[new_start];
                new_start++;

                int new_end = i - 1;
                int new_product2 = temp;
                while (arr[new_end] > 0) {
                    new_product2 /= arr[new_end];
                    new_end--;
                }
                new_product2 /= arr[new_end];
                new_end--;

                if (new_product1 > new_product2) {
                    if (new_product1 > ans_product) {
                        ans_product = new_product1;
                        ans_left = new_start;
                        ans_right = i - 1;
                    }
                }
                else {
                    if (new_product2 > ans_product) {
                        ans_product = new_product2;
                        ans_left = start;
                        ans_right = new_end;
                    }
                }
            }

            curr.clear();
        }
        else {
            if (curr.empty()) start = i;
            curr.push_back(arr[i]);
        }
    }

    if (!curr.empty()) {
        int temp = 1;
        for (int j = 0; j < curr.size(); j++) temp *= curr[j];

        if (temp > 0) {
            if (temp > ans_product) {
                ans_product = temp;
                ans_left = start;
                ans_right = n - 1;
            }
        }
        else {
            int new_start = start;
            int new_product1 = temp;
            while (arr[new_start] > 0) {
                new_product1 /= arr[new_start];
                new_start++;
            }
            new_product1 /= arr[new_start];
            new_start++;

            int new_end = n - 1;
            int new_product2 = temp;
            while (arr[new_end] > 0) {
                new_product2 /= arr[new_end];
                new_end--;
            }
            new_product2 /= arr[new_end];
            new_end--;

            if (new_product1 > new_product2) {
                if (new_product1 > ans_product) {
                    ans_product = new_product1;
                    ans_left = new_start;
                    ans_right = n - 1;
                }
            }
            else {
                if (new_product2 > ans_product) {
                    ans_product = new_product2;
                    ans_left = start;
                    ans_right = new_end;
                }
            }
        }
    }

    if (ans_left == -1) {
        cout << n << " " << 0 << endl;
        return;
    }
    cout << ans_left << ' ' << n - ans_right - 1 << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}