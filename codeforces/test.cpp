#include <bits/stdc++.h>

using namespace std;

#define int long long int

int subsetXOR(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    int m = (1 << (int)(log2(mx) + 1)) - 1;

    if (m < 0)
        return 0;

    vector<int> dp(m + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<int> temp_dp = dp;
        for (int j = 0; j <= m; j++)
            dp[j] = temp_dp[j] + temp_dp[j ^ arr[i - 1]];
    }

    return dp[0];
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << subsetXOR(arr, n) - 1 << endl;
}