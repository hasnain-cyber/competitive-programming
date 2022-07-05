#include <bits/stdc++.h>

#define MOD 1000000007
//#define MOD 998244353
#define MIN numeric_limits<int>::min()
#define MAX numeric_limits<int>::max()

#define int long long int
#define double long double

#define endl '\n'

using namespace std;

void solve_testcase() {
    int w, h, q;
    cin >> w >> h >> q;
    map<int, int> horizontal_parts, vertical_parts;
    horizontal_parts[w] = 1;
    vertical_parts[h] = 1;
    set<int> horizontal_cuts = {0, h}, vertical_cuts = {0, w};

    while (q--) {
        char type;
        cin >> type;
        int value;
        cin >> value;
        if (type == 'H') {
            auto upper_cut = horizontal_cuts.upper_bound(value);
            auto lower_cut = upper_cut;
            lower_cut--;

            horizontal_cuts.insert(value);

            vertical_parts[*upper_cut - *lower_cut]--;
            if (vertical_parts[*upper_cut - *lower_cut] == 0) vertical_parts.erase(*upper_cut - *lower_cut);

            vertical_parts[*upper_cut - value]++;
            vertical_parts[value - *lower_cut]++;
        } else {
            auto upper_cut = vertical_cuts.upper_bound(value);
            auto lower_cut = upper_cut;
            lower_cut--;

            vertical_cuts.insert(value);

            horizontal_parts[*upper_cut - *lower_cut]--;
            if (horizontal_parts[*upper_cut - *lower_cut] == 0) horizontal_parts.erase(*upper_cut - *lower_cut);

            horizontal_parts[*upper_cut - value]++;
            horizontal_parts[value - *lower_cut]++;
        }

        auto it1 = horizontal_parts.rbegin();
        auto it2 = vertical_parts.rbegin();

        cout << (it1->first) * (it2->first) << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--) {
        solve_testcase();
    }
}