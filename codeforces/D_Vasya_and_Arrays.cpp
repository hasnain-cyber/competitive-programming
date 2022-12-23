#include <bits/stdc++.h>

#define MOD 1000000007
// #define MOD 998244353
#define infinity numeric_limits<int>::max()

#define int long long int
#define double long double
#define pii pair<int, int>

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
    vector<int> arr1(n);
    int total_sum1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        total_sum1 += arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    int total_sum2 = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
        total_sum2 += arr2[i];
    }

    if (total_sum1 != total_sum2) {
        cout << -1 << endl;
        return;
    }
    
    int pointer1 = 0, pointer2 = 0;
    int sum1 = 0, sum2 = 0;
    int counter = 0;
    while (pointer1 < n && pointer2 < m) {
        sum1 += arr1[pointer1];
        sum2 += arr2[pointer2];
        pointer1++;
        pointer2++;

        counter++;

        while (sum1 != sum2) {
            if (sum1 < sum2) {
                if (pointer1 < n) {
                    sum1 += arr1[pointer1];
                    pointer1++;
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
            if (sum2 < sum1) {
                if (pointer2 < m) {
                    sum2 += arr2[pointer2];
                    pointer2++;
                } else {
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    cout << counter << endl;
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