#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int find_highest_power(int n, int k) {
    int ans = 0;
    int current_value = 1;
    while (current_value * k <= n) {
        ans++;
        current_value *= k;
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) pq.push(arr[i]);
        }

        set<int> used_powers;
        bool flag = true;
        while (!pq.empty() && flag) {
            int element = pq.top();
            pq.pop();

            int power = find_highest_power(element, k);
            if (used_powers.count(power))
                flag = false;
            else {
                used_powers.insert(power);
                element -= pow(k, power);
                if (element > 0) pq.push(element);
            }
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}