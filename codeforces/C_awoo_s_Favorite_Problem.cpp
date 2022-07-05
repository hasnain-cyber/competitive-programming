#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define MOD 1000000007
#define MIN numeric_limits<ll>::min()
#define MAX numeric_limits<ll>::max()

using namespace std;

bool find(string &s1, string &s2, int i, int j) {
    if (i > j) return true;
    if (s1[i] == s2[i]) return find(s1, s2, i + 1, j);
    if (s1[j] == s2[j]) return find(s1, s2, i, j - 1);

    if (s1[i] == 'a') {
        if (s2[i] == 'b') {
            int required_index = -1;
            for (int index = i; index <= j; index++) {
                if (s1[index] == 'c') return false;
                if (s1[index] == 'b') {
                    required_index = index;
                    break;
                }
            }
            swap(s1[i], s1[required_index]);
            return find(s1, s2, i + 1, j);
        } else
            return false;
    } else if (s1[i] == 'b') {
        if (s2[i] == 'c') {
            int required_index = -1;
            for (int index = i; index <= j; index++) {
                if (s1[index] == 'a') return false;
                if (s1[index] == 'c') {
                    required_index = index;
                    break;
                }
            }
            swap(s1[i], s1[required_index]);
            return find(s1, s2, i + 1, j);
        } else
            return false;
    } else
        return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s1[i]]++;
            mp[s2[i]]--;
        }

        bool flag = true;
        for (auto it : mp) {
            if (it.second != 0) {
                flag = false;
                break;
            }
        }

        if (flag) {
            if (find(s1, s2, 0, n - 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else
            cout << "NO" << endl;
    }
}