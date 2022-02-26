#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    set<long long> sum;
    long long l = 0;
    for (int i = 0; i < n; ++i)
    {
        l += a[i];
        sum.insert(l);
    }

    long long ans = 0;
    long long r = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        sum.erase(l);
        l -= a[i];
        r += a[i];
        if (sum.count(r))
            ans = max(ans, r);
    }

    cout << ans << endl;

    return 0;
}

// had to do this one in cpp because the python and pypy were giving tle.