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
    string a, b;
    cin >> a >> b;

    vector<int> freq(4, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == '0' && b[i] == '0') freq[0]++;
        else if (a[i] == '0' && b[i] == '1') freq[1]++;
        else if (a[i] == '1' && b[i] == '0') freq[2]++;
        else freq[3]++;
    }

    // two operations change the positions of 0 and 1, so if we have same no. of 1s, we can perform as many operations as the different places,
    // to get the required answer
    int ans = infinity;
    if (freq[1] == freq[2]) {
        ans = min(ans, freq[1] + freq[2]);
    }
    
    vector<int> freq2 = freq;
    swap(freq2[0], freq2[2]);
    swap(freq2[1], freq2[3]);
    freq2[1]--;
    freq2[3]++;
    if (freq2[1] == freq2[2]) ans = min(ans, 1 + freq2[2] + freq2[1]);
    
    swap(freq2[1], freq2[3]);
    swap(freq2[0], freq2[2]);
    freq2[0]--;
    freq2[2]++;
    if (freq2[1] == freq2[2]) ans = min(ans, 1 + freq2[2] + freq2[1]);
    
    if (ans == infinity) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve_testcase();
    }
}