#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

int reverse_number(int n) {
    int ans = 0;
    while (n > 0) {
        ans = 10 * ans + n % 10;
        n /= 10;
    }

    return ans;
}

int check_palindrome(int n) {
    return n == reverse_number(n);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> palindromes;
    palindromes.push_back(0);
    for (int i = 1; i <= 4 * 10000; i++) {
        if (check_palindrome(i)) palindromes.push_back(i);
    }
    int k = palindromes.size();

    int N = 40000;
    vector<vector<int>> dp(N + 1, vector<int>(k));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < k; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 1 || j == 1)
                dp[i][j] = 1;
            else if (i >= palindromes[j]) {
                dp[i][j] = (dp[i][j - 1] + dp[i - palindromes[j]][j]) % MOD;
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][k - 1] << endl;
    }
}