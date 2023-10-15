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

    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i] <= n)
            freq[arr[i]]++;
    }

    int mex = -1;
    for(int i = 0; i <= n; i++) {
        if(freq[i] == 0) {
            mex = i;
            break;
        }
    }

    
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}