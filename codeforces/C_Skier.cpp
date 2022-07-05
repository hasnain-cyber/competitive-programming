#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double
#define endl '\n'

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int ans = 0;
        pair<int, int> current_pos = {0, 0};
        set<pair<pair<int, int>, pair<int, int>>> visited_paths;
        for (int i = 0; i < n; i++) {
            pair<int, int> destination = current_pos;

            if (s[i] == 'N')
                destination.first -= 1;
            else if (s[i] == 'S')
                destination.first += 1;
            else if (s[i] == 'E')
                destination.second += 1;
            else
                destination.second -= 1;

            pair<pair<int, int>, pair<int, int>> path1 = {current_pos, destination};
            pair<pair<int, int>, pair<int, int>> path2 = {destination, current_pos};

            if (visited_paths.count(path1))
                ans += 1;
            else {
                ans += 5;
                visited_paths.insert(path1);
                visited_paths.insert(path2);
            }

            current_pos = destination;
        }

        cout << ans << endl;
    }
}