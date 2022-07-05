#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

bool sum_exists(const vector<int> &arr, int s) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == s) return true;
    }

    return false;
}

void solve_testcase() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> positive_elements, negative_elements;
    int count_zeros = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            positive_elements.push_back(arr[i]);
        else if (arr[i] < 0)
            negative_elements.push_back(arr[i]);
        else
            count_zeros++;
    }

    if (positive_elements.size() > 2 || negative_elements.size() > 2) {
        cout << "NO" << endl;
        return;
    }

    // one positive, one negative, one zero
    int s1 = 0, s2 = 0;
    for (int positive_element : positive_elements) s1 += positive_element;
    for (int negative_element : negative_elements) s2 += negative_element;

    if (count_zeros) {
        for (int posiive_element : positive_elements) {
            for (int negative_element : negative_elements) {
                if (!sum_exists(arr, posiive_element + negative_element)) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }

        if (positive_elements.size() == 2) {
            if (!sum_exists(arr, s1)) {
                cout << "NO" << endl;
                return;
            }
        }

        if (negative_elements.size() == 2) {
            if (!sum_exists(arr, s2)) {
                cout << "NO" << endl;
                return;
            }
        }

        if (count_zeros >= 3) {
            if (!sum_exists(arr, 0)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    // two positive, one negative, and one positive, two negative
    if (positive_elements.size() == 2) {
        for (int negative_element : negative_elements) {
            if (!sum_exists(arr, s1 + negative_element)) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (negative_elements.size() == 2) {
        for (int positive_element : positive_elements) {
            if (!sum_exists(arr, s2 + positive_element)) {
                cout << "NO" << endl;
                return;
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
    while (t--) {
        solve_testcase();
    }
}