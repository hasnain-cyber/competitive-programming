#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

vector<int> factors(int n) {
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int f1 = i, f2 = n / i;
            ans.push_back(f1);
            if (f1 != f2) ans.push_back(f2);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s += arr[i];
        }

        vector<int> factors_arr = factors(s);
        int ans = n - 1;
        for (int parts : factors_arr) {
            if (parts > n) continue;

            int divided_sum = s / parts;

            // check if divided sum can be acheived
            int current = 0, counter = 0;
            vector<int> parts_counter;
            bool flag = true;
            for (int i = 0; i < n && flag; i++) {
                current += arr[i];
                counter++;

                if (current == divided_sum) {
                    parts_counter.push_back(counter);
                    current = 0;
                    counter = 0;
                } else if (current > divided_sum)
                    flag = false;
            }

            if (flag) {
                int new_value = 0;
                for (int part : parts_counter) new_value += part - 1;
                ans = min(ans, new_value);
            }
        }

        cout << ans << endl;
    }
}