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
    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;

    string rgb = "RGB";
    int counter1 = 0, counter2 = 0, counter3 = 0;
    int ans1 = infinity, ans2 = infinity, ans3 = infinity;
    for (int i = 0; i < k; i++) {
        if (rgb[i % 3] != arr[i]) counter1++;
        if (rgb[(i + 1) % 3] != arr[i]) counter2++;
        if (rgb[(i + 2) % 3] != arr[i]) counter3++;
    }
    ans1 = min(ans1, counter1);
    ans2 = min(ans2, counter2);
    ans3 = min(ans3, counter3);

    for (int i = 0; i + k < n; i++) {
        if (arr[i] != rgb[i % 3]) counter1--;
        if (arr[i + k] != rgb[(i + k) % 3]) counter1++;
        ans1 = min(ans1, counter1);

        if (arr[i] != rgb[(i + 1) % 3]) counter2--;
        if (arr[i + k] != rgb[(i + 1 + k) % 3]) counter2++;
        ans2 = min(ans2, counter2);

        if (arr[i] != rgb[(i + 2) % 3]) counter3--;
        if (arr[i + k] != rgb[(i + 2 + k) % 3]) counter3++;
        ans3 = min(ans3, counter3);
    }

    cout << min({ans1, ans2, ans3}) << endl;
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